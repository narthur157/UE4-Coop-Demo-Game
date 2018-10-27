// Fill out your copyright notice in the Description page of Project Settings.

#include "SwarmComponent.h"
#include "CoopGame.h"
#include "Components/SphereComponent.h"

// Sets default values for this component's properties
USwarmComponent::USwarmComponent()
{
    ProximitySphere = CreateDefaultSubobject<USphereComponent>(TEXT("ProximitySphere"));
}

// Called when the game starts
void USwarmComponent::BeginPlay()
{
	Super::BeginPlay();

    ProximitySphere->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
    ProximitySphere->SetSphereRadius(ProximityRadius, true);
    ProximitySphere->SetCollisionResponseToChannel(COLLISION_WEAPON, ECollisionResponse::ECR_Ignore);
    ProximitySphere->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECollisionResponse::ECR_Ignore);
    ProximitySphere->OnComponentBeginOverlap.AddDynamic(this, &USwarmComponent::OnProximityOverlap);
    ProximitySphere->OnComponentEndOverlap.AddDynamic(this, &USwarmComponent::OnProximityEndOverlap);
}

void USwarmComponent::OnProximityOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    // TODO: Figure out a way to ignore components that arent the root component, this feels hacky?
    if (OtherActor->GetRootComponent() == OtherComp &&  OtherActor != GetOwner())
    {
        for (int32 i = 0; i < PowerUpActors.Num(); i++)
        {
            if (OtherActor->IsA(PowerUpActors[i]))
            {
                NumOverlappingActors++;
                PowerLevel = NumOverlappingActors * PowerGainedPerActor;
                OnPowerLevelChanged.Broadcast(NumOverlappingActors, PowerLevel);
            }
        }
    }
}

void USwarmComponent::OnProximityEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor->GetRootComponent() == OtherComp && Cast<APawn>(OtherActor) && OtherActor != GetOwner())
    {
        for (int32 i = 0; i < PowerUpActors.Num(); i++)
        {
            if (OtherActor->IsA(PowerUpActors[i]))
            {
                NumOverlappingActors--;
                // Prevent going below zero for some god-unknown reason
                if (NumOverlappingActors < 0)
                {
                    NumOverlappingActors = 0;
                }
                PowerLevel = NumOverlappingActors * PowerGainedPerActor;
                OnPowerLevelChanged.Broadcast(NumOverlappingActors, PowerLevel);
            }
        }
    }
}   


