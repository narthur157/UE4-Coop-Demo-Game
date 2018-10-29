// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupActor.h"
#include "Components/SphereComponent.h"
#include "Components/DecalComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "SPowerupActor.h"

// Sets default values
APickupActor::APickupActor()
{

    SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SphereComp->SetCollisionProfileName("Sensor");
    SphereComp->SetSphereRadius(70.0f);
    RootComponent = SphereComp;


    DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
    DecalComp->SetRelativeRotation(FRotator(90, 0, 0));
    DecalComp->DecalSize = FVector(64, 70.0f, 70.0f);
    DecalComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
    Respawn();
}

void APickupActor::Respawn()
{
    if (!PowerupClass)
    {
        UE_LOG(LogTemp, Error, TEXT("Powerup Class is null. %s"), *GetName());
        return;
    }

    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    PowerupInstance = GetWorld()->SpawnActor<ASPowerupActor>(PowerupClass, GetTransform(), SpawnParams);
}

void APickupActor::NotifyActorBeginOverlap(AActor * OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    if (PowerupInstance)
    {
        PowerupInstance->ActivatePowerup();
        PowerupInstance = nullptr;

        // Respawn timer
        GetWorld()->GetTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &APickupActor::Respawn, CooldownDuration);
    }
}

#if WITH_EDITOR
void APickupActor::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

    if ((PropertyName == FName(TEXT("SphereComp"))))
    {
        DecalComp->DecalSize = FVector(64, SphereComp->GetUnscaledSphereRadius(), SphereComp->GetUnscaledSphereRadius());
    }
}
#endif

