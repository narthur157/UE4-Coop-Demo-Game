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

void ASHitscanWeapon::Fire()
{
	if (Role < ROLE_Authority)
	{
		ServerFire();
	}
   
    AmmoInClip--;
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

        EPhysicalSurface SurfaceType = SurfaceType_Default;

        FVector TraceEnd = EyeLocation + (ShotDirection * 1000000);
        FVector TraceEndPoint = TraceEnd;

        FHitResult Hit;
        if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams))
		{
            AActor* HitActor = Hit.GetActor();

            // Get surface type to use to calculate damage multipler/impact effects
            SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());

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
                ActualDamage *= 4.0f;
			}

			OnHit(HitActor);

            UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, ShotDirection, Hit, Owner->GetInstigatorController(), this, DamageType);

            PlayImpactEffect(SurfaceType, Hit.ImpactPoint);

            TraceEndPoint = Hit.ImpactPoint;
        }

		// Replicated
		HitScanTrace.TraceTo = TraceEndPoint;
		HitScanTrace.SurfaceType = SurfaceType;
		
		// COND_SkipOwner is set
		OnRep_HitScanTrace();

        LastFireTime = GetWorld()->TimeSeconds;
    }
}

void ASHitscanWeapon::OnRep_HitScanTrace()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation());
    DrawTracerEffect(HitScanTrace.TraceTo);
	PlayImpactEffect(HitScanTrace.SurfaceType, HitScanTrace.TraceTo);
	DrawTracerEffect(HitScanTrace.TraceTo);
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

