#include "SPowerupActor.h"
#include "CoopGame.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

ASPowerupActor::ASPowerupActor()
{
    SetReplicates(true);
}

void ASPowerupActor::BeginPlay()
{
	Super::BeginPlay();
   
}

void ASPowerupActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASPowerupActor, bIsPowerupActive);
}

void ASPowerupActor::OnTickPowerup()
{
    TicksProcessed++;

    OnPowerupTicked();
    TRACE("%s ticked.", *GetName());
    if (TotalNumberOfTicks <= TicksProcessed)
    {
        OnExpired();
        bIsPowerupActive = false;
        OnRep_PowerupActive();
        GetWorldTimerManager().ClearTimer(TimerHandle_PowerupTick);
    }
}

void ASPowerupActor::OnRep_PowerupActive()
{
    FString LogActiveDeactive;
    LogActiveDeactive = bIsPowerupActive ? FString(TEXT("active")) : FString(TEXT("deactive"));
    TRACE("%s %s.", *GetName(), *LogActiveDeactive);
	
	if (PowerupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), PowerupSound, GetActorLocation());
	}

    OnPowerupStateChanged(bIsPowerupActive);
}

void ASPowerupActor::ActivatePowerup(AActor* InstigatorActor)
{
    TRACE("%s Activated on %s", *GetName(), *InstigatorActor->GetName());
    OnActivated(InstigatorActor);
    bIsPowerupActive = true;
    OnRep_PowerupActive();

    if (PowerupInterval > 0.0f)
    {
        GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerupActor::OnTickPowerup, PowerupInterval, true);
    }
    else
    {
        OnTickPowerup();
    }
}



