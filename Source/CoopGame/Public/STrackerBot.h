// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STrackerBot.generated.h"

class USHealthComponent;
class UMaterialInstanceDynamic;
class USphereComponent;
class USoundCue;

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

    UFUNCTION()
    void OnTakeDamage(USHealthComponent * ChangedHealthComp, float Health, float HealthDelta, 
        const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser);

    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float ExplosionRadius = 200;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float ProximityRadius = 150;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float ExplosionDamage = 100;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float SelfDestructTime = 5.0f;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float MovementForce = 1000;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    bool bUseVelocityChange = false;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float RequiredDistanceToTarget = 100;
    
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    USoundCue* SelfDestructTickSound = nullptr;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    USoundCue* ExplodeSound = nullptr;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    USoundCue* TriggeredSound = nullptr;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    UParticleSystem* ExplosionEffect = nullptr;

    FVector GetNextPathPoint();
    FVector NextPathPoint;
    void MoveTowardsTarget();

    bool bExploded = false;

    UPROPERTY(ReplicatedUsing=OnRep_TrackerBotAttached)
    bool bSelfDestructionAttached = false;

    UFUNCTION()
    void OnRep_TrackerBotAttached();

    UPROPERTY(ReplicatedUsing=OnRep_ExplodeTime)
    float ExplodeTime;

    UFUNCTION()
    void OnRep_ExplodeTime();


    FTimerHandle SelfDestructCountdownTimer;
    FTimerHandle SelfDestructionTickTimer;
    
    UFUNCTION()
    void SelfDestruct();
    UFUNCTION()
    void SelfDestructTick();

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
