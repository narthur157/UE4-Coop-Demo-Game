// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthComponent.h"
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

void USHealthComponent::HandleTakeDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
    if (Damage <= 0)
    {
        return;
    }

    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);
}

void USHealthComponent::OnRep_Health(float OldHealth)
{
    float Damage = Health - OldHealth;
    OnHealthChanged.Broadcast(this, Health, Damage, nullptr, nullptr, nullptr);
}
