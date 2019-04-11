// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageDealer.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageDealer : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COOPGAME_API IDamageDealer
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
    virtual float GetDamageModifier() { ensure(false); return 0.0f; };
	
};
