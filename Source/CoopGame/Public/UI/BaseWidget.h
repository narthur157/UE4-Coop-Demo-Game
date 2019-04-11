#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

UCLASS()
class COOPGAME_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	virtual void SetVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void VisibilityChanged(ESlateVisibility NewVisibility);
};
