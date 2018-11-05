// Fill out your copyright notice in the Description page of Project Settings.

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
#include "Engine/World.h"


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
        UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());

        // Perform line trace
        FVector EyeLocation;
        FRotator EyeRotation;
        Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
        

        FCollisionQueryParams QueryParams;
        QueryParams.AddIgnoredActor(Owner);
        QueryParams.AddIgnoredActor(this);
        QueryParams.bTraceComplex = true;
        QueryParams.bReturnPhysicalMaterial = true;

        // The value of the end point of the trace. If hit, hit location. Else, max trace range location
       

        // Bullet Spread
        float HalfRad = FMath::DegreesToRadians(BulletSpread);
        FVector ShotDirection = FMath::VRandCone(EyeRotation.Vector(), HalfRad, HalfRad);

        EPhysicalSurface SurfaceType = SurfaceType_Default;

        FVector TraceEnd = EyeLocation + (ShotDirection * 1000000);
        FVector TraceEndPoint = TraceEnd;

        FHitResult Hit;
        if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams))
        {
            // On Hit
            AActor* HitActor = Hit.GetActor();

            // Get surface type to use to calculate damage multipler/impact effects
            SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());

            // Better way of doing this in the future, maybe enure that owners are damage dealers
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

            // Do Damage
            UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, ShotDirection, Hit, Owner->GetInstigatorController(), this, DamageType);

            // Apply impact effects based on surface type
            PlayImpactEffect(SurfaceType, Hit.ImpactPoint);

            // Set Trace endpoint to the hit impact point
            TraceEndPoint = Hit.ImpactPoint;
        }

        // If we are the server, replicate the hitscan information out so other clients know where/how to play their effects
        if (Role == ROLE_Authority)
        {
            HitScanTrace.TraceTo = TraceEndPoint;
            HitScanTrace.SurfaceType = SurfaceType;
        }

        // Draw tracer effects
        DrawTracerEffect(TraceEndPoint);

        // Set last fire time
        LastFireTime = GetWorld()->TimeSeconds;
    }
}

void ASHitscanWeapon::OnRep_HitScanTrace()
{
    DrawTracerEffect(HitScanTrace.TraceTo);
    PlayImpactEffect(HitScanTrace.SurfaceType, HitScanTrace.TraceTo);
}

void ASHitscanWeapon::DrawTracerEffect(const FVector &TraceEndPoint)
{
    if (MuzzleEffect)
    {
        UGameplayStatics::SpawnEmitterAttached(MuzzleEffect, MeshComp, MuzzleSocketName);
    }

    if (TracerEffect)
    {
        FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
        UParticleSystemComponent* TracerComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TracerEffect, MuzzleLocation);
        if (TracerComp)
        {
            TracerComp->SetVectorParameter(TracerTargetName, TraceEndPoint);
        }
    }

    APawn* Owner = Cast<APawn>(GetOwner());
    if (Owner)
    {
        APlayerController* OwnerController = Cast<APlayerController>(Owner->GetController());
        if (OwnerController)
        {
            OwnerController->ClientPlayCameraShake(FireCamShake);
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

