#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Config.generated.h"

UCLASS(Config=Game)
class COOPGAME_API UConfig : public UObject
{
	GENERATED_BODY()

public:	
	UPROPERTY(Config)
	float MouseSensitivity = 1.0f;

	UFUNCTION(BlueprintCallable)
	void SetMouseSensitivity(float Sens);

	UFUNCTION(BlueprintCallable)
	float GetMouseSensitivity();

	static UConfig* GetConfigSingleton();
};
