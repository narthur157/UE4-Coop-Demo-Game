#include "SPowerupActor.h"
#include "CoopGame.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "SPulseGlowComponent.h"

ASPowerupActor::ASPowerupActor()
{
    SetReplicates(true);
}

void ASPowerupActor::BeginPlay()
{
	Super::BeginPlay();
   
}

void ASPowerupActor::MulticastDespawnPowerupEffect_Implementation()
{
	if (ActivePowerupEffect)
	{
		ActivePowerupEffect->DestroyComponent();
		ActivePowerupEffect = nullptr;
	}
}

void ASPowerupActor::MulticastSpawnPowerupEffect_Implementation(AActor* MyActor)
{
	ActivePulseComp = Cast<USPulseGlowComponent>(MyActor->GetComponentByClass(USPulseGlowComponent::StaticClass()));
	
	if (ActivePulseComp)
	{
		ActivePulseComp->BeginPulsing(1.0f, GlowColor, 0.75f, TotalNumberOfTicks * PowerupInterval);
	}

	UMeshComponent* InstMesh = Cast<UMeshComponent>(MyActor->GetComponentByClass(UMeshComponent::StaticClass()));
	ActivePowerupEffect = UGameplayStatics::SpawnEmitterAttached(PowerupEffect, InstMesh, NAME_None, PowerupEffectSpawnOffset, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);
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
		MulticastDespawnPowerupEffect();
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
	ActivatedFor = InstigatorActor;

    OnActivated(InstigatorActor);
    bIsPowerupActive = true;
    OnRep_PowerupActive();

	MulticastSpawnPowerupEffect(InstigatorActor);
    
	if (PowerupInterval > 0.0f)
    {
        GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerupActor::OnTickPowerup, PowerupInterval, true);
    }
    else
    {
        OnTickPowerup();
    }
}

bool ASPowerupActor::MulticastSpawnPowerupEffect_Validate(AActor* MyActor)
{
	return true;
}

bool ASPowerupActor::MulticastDespawnPowerupEffect_Validate()
{
	return true;
}
