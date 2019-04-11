#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

class USphereComponent;
class UDecalComponent;
class ASPowerupActor;

UCLASS()
class COOPGAME_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APickupActor();

protected:
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category= "Components")
    USphereComponent* SphereComp = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UDecalComponent* DecalComp = nullptr;

    UPROPERTY(EditAnywhere, Category = "Powerup")
    float CooldownDuration = 10.0f;

    FTimerHandle TimerHandle_RespawnTimer;

    UPROPERTY(EditInstanceOnly, Category = "Powerup")
    TSubclassOf<ASPowerupActor> PowerupClass = nullptr;

    ASPowerupActor* PowerupInstance = nullptr;

    void Respawn();

public:	
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};

