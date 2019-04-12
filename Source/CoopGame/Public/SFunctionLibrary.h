#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SFunctionLibrary.generated.h"

class UWorld;
class UConfig;

UCLASS()
class COOPGAME_API USFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool FindFloor(UWorld* World, FVector FindFrom, FVector& OutFoundLocation );

	UFUNCTION(BlueprintCallable)
	static UConfig* GetConfigSingleton();
};
