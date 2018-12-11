#include "SHitscanWeapon.h"
#include "DrawDebugHelpers.h"
#include "Particles/ParticleSystem.h"
#include "CoopGame.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "DamageDealer.h"

void ASHitscanWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASHitscanWeapon, AmmoInClip);
    DOREPLIFETIME_CONDITION(ASHitscanWeapon, HitScanTrace, COND_SkipOwner);
}


void ASHitscanWeapon::PerformHitScan(bool bDoDamage, bool bConsumeAmmo)
{
    AActor* Owner = GetOwner();
    if (Owner)
    {
        FVector EyeLocation;
        FRotator EyeRotation;
        Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

        FCollisionQueryParams QueryParams;
        QueryParams.AddIgnoredActor(Owner);
        QueryParams.AddIgnoredActor(this);
        QueryParams.bTraceComplex = true;
        QueryParams.bReturnPhysicalMaterial = true;

        // Bullet Spread
        float HalfRad = FMath::DegreesToRadians(BulletSpread);
        FVector ShotDirection = FMath::VRandCone(EyeRotation.Vector(), HalfRad, HalfRad);
        FVector TraceEnd = EyeLocation + (ShotDirection * 1000000);

        FHitResult OutHit;
        if (GetWorld()->LineTraceSingleByChannel(OutHit, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams))
        {
            OnTraceHit(OutHit, ShotDirection, bDoDamage);
            HitScanTrace.TraceTo = OutHit.ImpactPoint;
            HitScanTrace.SurfaceType = UPhysicalMaterial::DetermineSurfaceType(OutHit.PhysMaterial.Get());
        }
        else
        {
            HitScanTrace.TraceTo = TraceEnd;
            HitScanTrace.SurfaceType = SurfaceType_Default;
        }

        // Force the struct to replicate
        HitScanTrace.HitIndex = (HitScanTrace.HitIndex == 255) ? 0 : HitScanTrace.HitIndex + 1;

        // Need to call this in order to play the effects ourselves
        OnRep_HitScanTrace();

        LastFireTime = GetWorld()->TimeSeconds;
    }

    if (bConsumeAmmo)
    {
        AmmoInClip--;
    }
}

void ASHitscanWeapon::OnTraceHit(FHitResult Hit, FVector ShotDirection, bool bDoDamage)
{
    AActor* HitActor = Hit.GetActor();
    AActor* Owner = GetOwner();
    if (!HitActor || !Owner) { return; }

    // Get surface type to use to calculate damage multipler/impact effects
    EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
    OnHit(HitActor);

    // Calculate and apply damage for this shot
    if (bDoDamage)
    {
        // Better way of doing this in the future, maybe ensure that owners are damage dealers
        IDamageDealer* DamageDealer = Cast<IDamageDealer>(GetOwner());
        // Calculate damage multiplier
        float ActualDamage = BaseDamage;

        if (DamageDealer)
        {
            ActualDamage += (DamageDealer->GetDamageModifier() / 100) * ActualDamage;
        }

        if (SurfaceType == SURFACE_FLESHVULNERABLE)
        {
            ActualDamage *= HeadshotBonus;
        }

        UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, ShotDirection, Hit, Owner->GetInstigatorController(), this, DamageType);
    }
}

// To display effects on clients
void ASHitscanWeapon::OnRep_HitScanTrace()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation());
    DrawTracerEffect(HitScanTrace.TraceTo);
	PlayImpactEffect(HitScanTrace.SurfaceType, HitScanTrace.TraceTo);
}

void ASHitscanWeapon::DrawTracerEffect(const FVector &TraceEndPoint)
{
    FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
    if (MuzzleEffect)
    {
		// TODO: This should work
		// UGameplayStatics::SpawnEmitterAttached(MuzzleEffect, MeshComp, MuzzleSocketName);
		FVector ShotDirection = TraceEndPoint - MuzzleLocation;
		ShotDirection.Normalize();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleEffect, MuzzleLocation, ShotDirection.Rotation());
    }

    if (TracerEffect)
    {
        UParticleSystemComponent* TracerComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TracerEffect, MuzzleLocation);
        if (TracerComp)
        {
            TracerComp->SetVectorParameter(TracerTargetName, TraceEndPoint);
        }
    }
}

void ASHitscanWeapon::PlayImpactEffect(EPhysicalSurface SurfaceType, FVector ImpactPoint)
{
    UParticleSystem* SelectedEffect = nullptr;
    switch (SurfaceType)
    {
        case SURFACE_FLESHDEFAULT:
        case SURFACE_FLESHVULNERABLE:
            SelectedEffect = FleshImpactEffect;
            break;
        default:
            SelectedEffect = DefaultImpactEffect;
            break;
    }

    if (SelectedEffect)
    {
		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
        FVector ShotDirection = ImpactPoint - MuzzleLocation;
        ShotDirection.Normalize();
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SelectedEffect, ImpactPoint, ShotDirection.Rotation());
    }
}

