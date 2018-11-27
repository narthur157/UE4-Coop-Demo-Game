#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SWeaponWidget.generated.h"

class USWeaponComponent;

UCLASS()
class COOPGAME_API USWeaponWidget : public UUserWidget
{
    GENERATED_BODY()

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "WeaponComponent")
    USWeaponComponent* WeaponComponent = nullptr;

public:
    // In the future this widget should utiliize an observer pattern and bind to events on the weapon component
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponHUD")
        void RefreshWeapons();
	
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponHUD")
        void RefreshAmmo();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponHUD")
        void InitializeWeaponWidget(USWeaponComponent* NewWeaponComponent, int32 NumberWeaponSlots);
};
