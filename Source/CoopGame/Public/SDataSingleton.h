// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SWeapon.h"
#include "SDataSingleton.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class COOPGAME_API USDataSingleton : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmmoIcons")
    TMap<EAmmoType, UTexture2D*> AmmoIcons;
	
	
};
