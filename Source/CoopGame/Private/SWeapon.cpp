// Fill out your copyright notice in the Description page of Project Settings.

#include "SWeapon.h"
#include "DrawDebugHelpers.h"
#include "Particles/ParticleSystem.h"
#include "CoopGame.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/World.h"


static int32 DebugWeaponDrawing = 0;
FAutoConsoleVariableRef CVARDebugWeaponDrawing(
    TEXT("COOP.DebufWeapons"),
    DebugWeaponDrawing,
    TEXT("Draw Debug Lines for Weapons"),
    ECVF_Cheat);

// Sets default values
ASWeapon::ASWeapon()
{
    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComp;

    
}

void ASWeapon::BeginPlay()
{
    Super::BeginPlay();

    LastFireTime = -999999.0f;
}

void ASWeapon::Fire()
{
    AActor* Owner = GetOwner();
    if (Owner)
    {
        // Perform line trace
        FVector EyeLocation;
        FRotator EyeRotation;
        Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
        
        FVector TraceEnd = EyeLocation + (EyeRotation.Vector() * 1000000);
        
        FCollisionQueryParams QueryParams;
        QueryParams.AddIgnoredActor(Owner);
        QueryParams.AddIgnoredActor(this);
        QueryParams.bTraceComplex = true;
        QueryParams.bReturnPhysicalMaterial = true;

     
        // The value of the end point of the trace. If hit, hit location. Else, max trace range location
        FVector TraceEndPoint = TraceEnd;

        FHitResult Hit;
        if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams))
        {
            // Hit 
            AActor* HitActor = Hit.GetActor();

            FVector ShotDirection = EyeRotation.Vector();
            EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());

            float ActualDamage = BaseDamage;
            if (SurfaceType == SURFACE_FLASHVULNERABLE)
            {
                ActualDamage *= 4.0f;
            }

            UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, ShotDirection, Hit, Owner->GetInstigatorController(), this, DamageType);
            
            UParticleSystem* SelectedEffect = nullptr;
            switch (SurfaceType)
            {
            case SURFACE_FLESHDEFAULT:
            case SURFACE_FLASHVULNERABLE:
                SelectedEffect = FleshImpactEffect;
                break;
            default:
                SelectedEffect = DefaultImpactEffect;
                break;
            }
            if (SelectedEffect)
            {
                UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SelectedEffect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());

            }
            TraceEndPoint = Hit.ImpactPoint;
        }

        DrawTracerEffect(TraceEndPoint);
       
        if (DebugWeaponDrawing > 0)
        {
            DrawDebugLine(GetWorld(), EyeLocation, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f);
        }
        LastFireTime = GetWorld()->TimeSeconds;
    }
}

void ASWeapon::StartFire()
{
    float FirstDelay = FMath::Max(LastFireTime + TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);
    GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &ASWeapon::Fire, TimeBetweenShots, true, FirstDelay);
}

void ASWeapon::StopFire()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
}

void ASWeapon::DrawTracerEffect(const FVector &TraceEndPoint)
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
    if(Owner)
    {
        APlayerController* OwnerController = Cast<APlayerController>(Owner->GetController());
        if (OwnerController)
        {
            OwnerController->ClientPlayCameraShake(FireCamShake);
        }
    }
}
