// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthComponent.h"
#include "SGameMode.h"
#include "CoopGame.h"
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
    }
}

// This only runs onn server because we are only binding to this delegate onn server
void USHealthComponent::HandleTakeDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
    //IsFriendly(DamagedActor, InstigatedBy->GetPawn())
    if (Damage <= 0 || bIsDead || (!InstigatedBy && false))
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
        TRACE("%s has died.", *GetOwner()->GetName());
        ASGameMode* GM = Cast<ASGameMode>(GetWorld()->GetAuthGameMode());
        if (GM)
        {
            // TRACE("%s has died. Died to: %s", *GetOwner()->GetName(), *InstigatedBy->GetPawn()->GetName());
            GM->OnActorKilled(GetOwner(), InstigatedBy->GetPawn(), InstigatedBy);
        }
        bIsDead = true;
    }
}

void USHealthComponent::OnRep_Health(float OldHealth)
{
    float Damage = Health - OldHealth;
    TRACE("%s Health changed. Current Health: %f", *GetOwner()->GetName(), Health);
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

bool USHealthComponent::IsFriendly(AActor * ActorOne, AActor * ActorTwo)
{
    if (!ActorOne || !ActorTwo) { return true; }

    USHealthComponent* HealthCompOne = ActorOne->FindComponentByClass<USHealthComponent>();
    USHealthComponent* HealthCompTwo = ActorTwo->FindComponentByClass<USHealthComponent>();

    if (HealthCompOne && HealthCompTwo)
    {
        if (ActorOne == ActorTwo && HealthCompOne->bDamageSelf)
        {
            return false;
        }

        return HealthCompOne->TeamNum == HealthCompTwo->TeamNum;
    }

    return true;
}
