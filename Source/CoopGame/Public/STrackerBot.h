// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DamageDealer.h"
#include "ITeamMember.h"
#include "STrackerBot.generated.h"

class USHealthComponent;
class UMaterialInstanceDynamic;
class USphereComponent;
class USoundCue;

UCLASS()
class COOPGAME_API ASTrackerBot : public APawn, public IDamageDealer, public ITeamMember
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASTrackerBot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
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
    float SelfDestructTime = 3.0f;
    
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float MovementForce = 5000;
	
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
	float MaxSpeed = 1000;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    bool bUseVelocityChange = false;

    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    float RequiredDistanceToTarget = 100;
	// Recalc the navigation path every x seconds
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
	float RefreshInterval = 0.5f;
    
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    USoundCue* SelfDestructTickSound = nullptr;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    USoundCue* ExplodeSound = nullptr;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    USoundCue* TriggeredSound = nullptr;
    UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
    UParticleSystem* ExplosionEffect = nullptr;

	// If true, bot will teleport on to player's back once in range
	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
	bool bBotAttachesToPlayer = false;

    FVector GetNextPathPoint();
    FVector NextPathPoint;
    void MoveTowardsTarget(float DeltaTime);

    bool bTriggered = false;

    UPROPERTY(ReplicatedUsing=OnRep_Exploded)
    bool bExploded = false;

    UPROPERTY(ReplicatedUsing=OnRep_TrackerBotAttached)
    bool bSelfDestructionAttached = false;

    UPROPERTY(ReplicatedUsing = OnRep_ExplodeTime)
    float ExplodeTime = 0.0f;

    UFUNCTION()
    void OnRep_TrackerBotAttached();

    UFUNCTION()
    void OnRep_ExplodeTime();

    UFUNCTION()
    void OnRep_Exploded();

	/**
	 * @param Pawn to attach to. Must have a "Back" socket
	 * @returns False if bot did not attach for any reason
	 */
	UFUNCTION()
	bool AttachBotToActor(APawn* OtherPawn);

    FTimerHandle SelfDestructCountdownTimer;
    FTimerHandle SelfDestructionTickTimer;
    FTimerHandle TimerHandle_RefreshPath;
    
    UFUNCTION()
    void SelfDestruct();
    UFUNCTION()
    void SelfDestructTick();

    UPROPERTY(BlueprintReadWrite, Category = "Power")
    float DamageModifier = 1.0f;

    UFUNCTION()
    void OnProximityRadiusOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

    UFUNCTION()
    void RefreshPath();
public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

    // IDamageDealer
    virtual float GetDamageModifier() override { return DamageModifier; }

    // ITeamMember 
    virtual uint8 GetTeamID() override;
	
};
