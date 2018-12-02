// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "SAffix.generated.h"

/**
 * 
 */
UCLASS(ABSTRACT, Blueprintable)
class COOPGAME_API ASAffix : public AInfo
{
	GENERATED_BODY()
	
public:

    ASAffix();

    UFUNCTION(BlueprintCallable, Category = "Affix")
    void ApplyToActor(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "Affix")
    FText GetAffixDescription() { return AffixDescription; }

    UFUNCTION(BlueprintCallable, Category = "Affix")
    UTexture2D* GetAffixIcon() { return AffixIcon; }

protected:

    UFUNCTION(BlueprintImplementableEvent, Category = "Affix")
    void OnApplyToActor(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "Affix")
    void AffixTick();

    UFUNCTION(BlueprintImplementableEvent, Category = "Affix")
    void OnTicked();

    UFUNCTION(BlueprintCallable, Category = "Affix")
    void Disable();

    UFUNCTION(BlueprintImplementableEvent, Category = "Affix")
    void OnDisabled();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Affix")
    UTexture2D* AffixIcon;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Affix")
    FText AffixDescription;

    UPROPERTY(BlueprintReadOnly, Category = "Affix")
    TArray<AActor*> ActorsActivatedFor;
	
    UPROPERTY(EditDefaultsOnly, Category = "Affix")
    float TickInterval = 0.0f;

    FTimerHandle TimerHandle_AffixTick;


};
