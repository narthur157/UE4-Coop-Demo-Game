// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthComponent.h"
#include "SGameMode.h"
#include "SGameState.h"
#include "CoopGame.h"
#include "Engine/Engine.h"
#include "Gameplay/GameplayComponents/TeamComponent.h"
#include "Net/UnrealNetwork.h"


// Sets default values for this component's properties
USHealthComponent::USHealthComponent()
{
    SetIsReplicated(true);
	// ...
}

void USHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(USHealthComponent, Health);

}

// Called when the game starts
void USHealthComponent::BeginPlay()
{
	Super::BeginPlay();

    // Only perform if we are the server
    if (GetOwnerRole() == ROLE_Authority)
    {
        AActor* Owner = GetOwner();
        if (Owner)
        {
            Owner->OnTakeAnyDamage.AddDynamic(this, &USHealthComponent::HandleTakeDamage);
        }
        Health = MaxHealth;
        OnHealthChanged.Broadcast(this, Health, 0, nullptr, nullptr, nullptr);
    }

}

// This only runs on server because we are only binding to this delegate on server
void USHealthComponent::HandleTakeDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
    //IsFriendly(DamagedActor, InstigatedBy->GetPawn())
    ASGameMode* GM = Cast<ASGameMode>(GetWorld()->GetAuthGameMode());

    // @TODO right now self damage is simply just enabled, because we need the trackerbot to be able to kill itself essentially
    // This is not correct.
    if (Damage <= 0 || bIsDead || (!GM->bIsFriendlyFireEnabled && UTeamComponent::IsActorFriendly(DamagedActor, InstigatedBy->GetPawn()) && DamagedActor != InstigatedBy->GetPawn()))
    {
        return;
    }

    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

    FString InstigatedByS = InstigatedBy && InstigatedBy->GetPawn() ? *InstigatedBy->GetPawn()->GetName() : NULLSTRING;
    FString DamageCauserS = DamageCauser ? *DamageCauser->GetName() : NULLSTRING;
    TRACE("%s inflicts %f damage on %s using %s . Current Health: %f",
        *InstigatedByS, 
        Damage, 
        *GetOwner()->GetName(), 
        *DamageCauserS,
        Health);

    OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);

    if (Health <= 0 && !bIsDead)
    {
        if (GM && InstigatedBy && InstigatedBy->GetPawn() && GetOwner())
        {
            TRACE("%s", *DamageCauser->GetName());
            GM->OnActorKilled(GetOwner(), InstigatedBy->GetPawn(), DamageCauser);
        }
        bIsDead = true;
    }
}

void USHealthComponent::OnRep_Health(float OldHealth)
{
    float Damage = OldHealth - Health;
    TRACE("%s Health changed. Current Health: %f. Damage: %f", *GetOwner()->GetName(), Health, Damage);
    OnHealthChanged.Broadcast(this, Health, Damage, nullptr, nullptr, nullptr);
}

void USHealthComponent::Heal(float HealAmount)
{
    if (HealAmount <= 0.0f || Health <= 0.0f)
    {
        return;
    }

    TRACE("%s healed for %f hp.", *GetOwner()->GetName(), HealAmount);
    Health = FMath::Clamp(Health + HealAmount, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(this, Health, -HealAmount, nullptr, nullptr, nullptr);
}

