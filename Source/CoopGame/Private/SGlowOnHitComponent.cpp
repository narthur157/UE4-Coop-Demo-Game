#include "SGlowOnHitComponent.h"
#include "SHealthComponent.h"

USGlowOnHitComponent::USGlowOnHitComponent()
{
}

void USGlowOnHitComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* MyOwner = GetOwner();

	if (!ensureAlways(MyOwner)) { return; }
	
	USHealthComponent* HealthComp = Cast<USHealthComponent>(MyOwner->GetComponentByClass(USHealthComponent::StaticClass()));
	HealthComp->OnHealthChanged.AddDynamic(this, &USGlowOnHitComponent::OnHealthChanged);

	if (!ensureMsgf(HealthComp, TEXT("GlowOnHitComponent requires a HealthComp to be set on its parent")))
	{
		return;
	}
}

void USGlowOnHitComponent::OnHealthChanged(USHealthComponent * ChangedHealthComp, float Health, float HealthDelta, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	AActor* MyOwner = GetOwner();

	if (!ensureAlways(MyOwner)) { return; }

	UMeshComponent* MeshComp = Cast<UMeshComponent>(MyOwner->GetComponentByClass(UMeshComponent::StaticClass()));
	
	if (!ensure(MeshComp)) { return; }
	
	UMaterialInstanceDynamic* MatInst = Cast<UMaterialInstanceDynamic>(MeshComp->GetMaterial(GlowMaterialIndex));

	if (!ensureMsgf(MatInst, TEXT("GlowOnHitComponent requires a mesh component with a material instance at GlowMaterialIndex")))
	{
		return;
	}

	FColor GlowColor = HealthDelta > 0 ? HitGlowColor : HealGlowColor;

	USGlowOnHitComponent::FlashGlow(MatInst, GetWorld()->TimeSeconds, GlowColor, 5.0f);
}

void USGlowOnHitComponent::FlashGlow(UMaterialInstanceDynamic* MatInst, float TimeSeconds, FColor GlowColor, float Intensity /*= 0.0f*/)
{
	MatInst->SetVectorParameterValue("HitGlowColor", GlowColor);
	MatInst->SetScalarParameterValue("HitEmissiveIntensity", Intensity);
	MatInst->SetScalarParameterValue("LastTimeDamageTaken", TimeSeconds);
}

