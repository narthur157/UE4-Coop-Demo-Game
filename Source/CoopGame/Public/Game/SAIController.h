// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SAIController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAIPawnChanged, APawn*, NewPawn);


UENUM()
enum class FFocusType : uint8
{
    Default,
    Move,
    Target,
    GameplayOne,
    GameplayTwo,
    GameplayThree,
    Max
};

/**
 * 
 */
UCLASS()
class COOPGAME_API ASAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;
    void SetPawn(APawn* InPawn) override;

    /** Brain component exposing */
    UFUNCTION(BlueprintCallable, Category = "AIController")
    void PauseLogic(const FString& Reason);
    UFUNCTION(BlueprintCallable, Category = "AIController")
    void ResumeLogic(const FString& Reason);

    /** Focus exposing */
    UFUNCTION(BlueprintCallable, Category = "AIController")
    void ClearFocusForPriority(int32 InPriority);
    UFUNCTION(BlueprintCallable, Category = "AIController")
    void ClearFocusForPriorityType(FFocusType Type);

    UFUNCTION(BlueprintPure, Category = "AIController")
    AActor* GetFocusActorForPriority(int32 InPriority);
    UFUNCTION(BlueprintPure, Category = "AIController")
    AActor* GetFocusActorForFocusType(FFocusType Type);

    UFUNCTION(BlueprintPure, Category = "AIController")
    FVector GetFocalPointForPriority(int32 InPriority);
    UFUNCTION(BlueprintPure, Category = "AIController")
    FVector GetFocalPointForPriorityType(FFocusType Type);

    // Sets the focus, returning the priority that the focus was set for, or -1 if a focus could not be set
    // If the type is max, the current focus will be set to whatever is passed in
    UFUNCTION(BlueprintCallable, Category = "AIController")
    int32 SetFocusActorForPriorityType(FFocusType Type, AActor* Actor);
    UFUNCTION(BlueprintCallable, Category = "AIController")
    int32 SetFocusActorForPriority(int32 InPriority, AActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "AIController")
    int32 SetFocalPointForPriorityType(FFocusType Type, FVector Point);
    UFUNCTION(BlueprintCallable, Category = "AIController")
    int32 SetFocalPointForPriority(int32 InPriority, FVector Point);


    UFUNCTION(BlueprintCallable, Category = "AIController")
    void SetCurrentTarget(AActor* NewTarget);
    UFUNCTION(BlueprintPure, Category = "AIController")
    AActor* GetCurrentTarget();


protected:

    UPROPERTY(BlueprintAssignable, Category = "PawnData")
    FOnAIPawnChanged OnPawnChanged;

    UFUNCTION(BlueprintImplementableEvent, Category = "AController")
    void OnPawnChange();

};
