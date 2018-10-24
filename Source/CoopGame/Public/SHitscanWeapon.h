// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SHitscanWeapon.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API ASHitscanWeapon : public ASWeapon
{
	GENERATED_BODY()
	
	
public:

protected:

    virtual void Fire() override;

    void DrawTracerEffect(const FVector &TraceEndPoint);

public:

};
