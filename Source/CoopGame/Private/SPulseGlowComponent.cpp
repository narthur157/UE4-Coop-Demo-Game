#include "SPulseGlowComponent.h"

USPulseGlowComponent::USPulseGlowComponent()
{
}

void USPulseGlowComponent::BeginPulsing(float Intensity /*= 0.0f*/, FColor Color /*= FColor::White*/, float Frequency /*= 1.0f*/, float Duration /* = -1.0f */)
{
	AActor* MyOwner = GetOwner();

	if (!ensureAlways(MyOwner)) { return; }

	UMeshComponent* MeshComp = Cast<UMeshComponent>(MyOwner->GetComponentByClass(UMeshComponent::StaticClass()));

	if (!ensure(MeshComp)) { return; }

	MatInst = Cast<UMaterialInstanceDynamic>(MeshComp->GetMaterial(PulseMaterialIndex));

	if (!ensureMsgf(MatInst, TEXT("SPulseGlowComponent requires a mesh component with a material instance at GlowMaterialIndex")))
	{
		return;
	}

	SetParams(MatInst, Intensity, Color, Frequency);
	
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &USPulseGlowComponent::StopPulsing, Duration, false);
	
	FPulseData NewPulse = FPulseData(Handle, Intensity, Color, Frequency, Duration);
	ActivePulses.Add(NewPulse);
}

void USPulseGlowComponent::SetParams(UMaterialInstanceDynamic* MatInstance, float Intensity /*= 0.0f*/, FColor Color /*= FColor::White*/, float Frequency /*= 1.0f*/)
{
	MatInstance->SetScalarParameterValue("PulseFreq", Frequency);
	MatInstance->SetScalarParameterValue("PulseIntensity", Intensity);
	MatInstance->SetVectorParameterValue("GlowColor", Color);
}

void USPulseGlowComponent::StopPulsing()
{
	ActivePulses.Pop();

	if (ActivePulses.Num() > 0)
	{
		FPulseData PData = ActivePulses.Last();
		USPulseGlowComponent::SetParams(MatInst, PData.Intensity, PData.Color, PData.Frequency);
	}
	else
	{
		USPulseGlowComponent::SetParams(MatInst);
	}
}

