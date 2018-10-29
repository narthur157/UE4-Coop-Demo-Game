// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthComponent.h"
#include "SGameMode.h"
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
    if (Damage <= 0 || bIsDead)
    {
        return;
    }

    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);

    if (Health <= 0 && !bIsDead)
    {
        bIsDead = true;
        ASGameMode* GM = Cast<ASGameMode>(GetWorld()->GetAuthGameMode());
        if (GM)
        {
            GM->OnActorKilled.Broadcast(GetOwner(), DamageCauser, InstigatedBy);
        }
    }
}

void USHealthComponent::OnRep_Health(float OldHealth)
{
    float Damage = Health - OldHealth;
    OnHealthChanged.Broadcast(this, Health, Damage, nullptr, nullptr, nullptr);
}


void USHealthComponent::Heal(float HealAmount)
{
    if (HealAmount <= 0.0f || Health <= 0.0f)
    {
        return;
    }

    Health = FMath::Clamp(Health + HealAmount, 0.0f, MaxHealth);

    OnHealthChanged.Broadcast(this, Health, -HealAmount, nullptr, nullptr, nullptr);

}