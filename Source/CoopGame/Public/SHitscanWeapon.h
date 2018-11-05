#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SHitscanWeapon.generated.h"

// Information for a sngle hitscan lnne trace
USTRUCT()
struct FHitScanTrace
{
    GENERATED_BODY()

public:

    UPROPERTY()
    TEnumAsByte<EPhysicalSurface> SurfaceType;

    UPROPERTY()
    FVector_NetQuantize TraceTo;

};

UCLASS()
class COOPGAME_API ASHitscanWeapon : public ASWeapon
{
	GENERATED_BODY()
	

protected:

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<UDamageType> DamageType;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float BaseDamage = 20.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon", meta = (ClampMin=0.0f))
    float BulletSpread = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* DefaultImpactEffect = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* FleshImpactEffect = nullptr;

    UPROPERTY(ReplicatedUsing = OnRep_HitScanTrace)
    FHitScanTrace HitScanTrace;

    UFUNCTION()
    void OnRep_HitScanTrace();

    virtual void Fire() override;

    void DrawTracerEffect(const FVector &TraceEndPoint);

    void PlayImpactEffect(EPhysicalSurface SurfaceType, FVector ImpactPoint);

public:

};
