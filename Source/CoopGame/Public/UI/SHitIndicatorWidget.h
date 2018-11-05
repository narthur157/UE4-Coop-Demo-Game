#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SHitIndicatorWidget.generated.h"

class UWidgetAnimation;

UCLASS()
class COOPGAME_API USHitIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UWidgetAnimation* FadeAnimation;

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void PlayHitAnimation();
	
};
