// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STrackerBot.generated.h"

class USHealthComponent;
class UMaterialInstanceDynamic;
class USphereComponent;

UCLASS()
class COOPGAME_API ASTrackerBot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASTrackerBot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleDefaultsOnly, Category = "Components")
        UStaticMeshComponent* MeshComp = nullptr;

    UPROPERTY(VisibleDefaultsOnly, Category = "Components")
     USHealthComponent* HealthComp = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
        USphereComponent* ProximityExplosionRadius = nullptr;

    // Pulse material
    UMaterialInstanceDynamic* MatInstance = nullptr;

    FVector GetNextPathPoint();
    FVector NextPathPoint;

    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float MovementForce = 1000;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    bool bUseVelocityChange = false;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float RequiredDistanceToTarget = 100;

    UFUNCTION()
    void OnTakeDamage(USHealthComponent * ChangedHealthComp, float Health, float HealthDelta, 
        const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser);

    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    UParticleSystem* ExplosionEffect = nullptr;

    float ExplosionRadius = 200;
    float ProximityRadius = 150;
    float ExplosionDamage = 100;
    void SelfDestruct();
    bool bExploded = false;
public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
