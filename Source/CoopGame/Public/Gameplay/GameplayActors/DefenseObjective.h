// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefenseObjective.generated.h"

class USHealthComponent;
class UTeamComponent;

UCLASS()
class COOPGAME_API ADefenseObjective : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADefenseObjective();

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_ObjectiveDestroyed)
    bool bObjectiveDestroyed = false;

    UFUNCTION(BlueprintCallable, Category = "DefenseObjective")
    void OnRep_ObjectiveDestroyed();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "ObjectiveHealth")
    USHealthComponent* HealthComp;

    UPROPERTY(VisibleAnywhere, Category = "Team")
    UTeamComponent* TeamComp;

    UFUNCTION(BlueprintImplementableEvent, Category = "DefenseObjective")
    void OnHealthComponentTakeDamage(USHealthComponent* DamagedHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

    UFUNCTION(BlueprintImplementableEvent, Category = "DefenseObjective")
    void OnObjectiveDestroyed();
	
};
