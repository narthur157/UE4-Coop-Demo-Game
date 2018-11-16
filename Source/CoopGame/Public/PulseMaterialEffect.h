#pragma once
#include "CoreMinimal.h"

class UMaterialInstanceDynamic;

class COOPGAME_API PulseMaterialEffect
{
public:
	PulseMaterialEffect();

	static void SetParams(UMaterialInstanceDynamic* MatInstance, float Intensity = 0.0f, FColor Color = FColor::White, float Frequency = 1.0f);
	
	~PulseMaterialEffect();
};
