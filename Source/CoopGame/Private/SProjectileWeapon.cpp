// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"
#include "SProjectile.h"
#include "Engine/World.h"
#include "Components/SkeletalMeshComponent.h"


void ASProjectileWeapon::Fire()
{
    if (Role < ROLE_Authority)
    {
        ServerFire();
        return;
    }

    if (ProjectileClass && GetOwner())
    {
        FVector ProjectileSpawnLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
        FRotator ProjectileSpawnRotation;
        FVector OutViewPointLocation;
        GetOwner()->GetActorEyesViewPoint(OutViewPointLocation, ProjectileSpawnRotation);

        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        SpawnParams.Instigator = Cast<APawn>(GetOwner());
        ASProjectile* NewProjectile = GetWorld()->SpawnActor<ASProjectile>(ProjectileClass, ProjectileSpawnLocation, ProjectileSpawnRotation, SpawnParams);

        if (Role == ROLE_Authority)
        {
            UE_LOG(LogTemp, Warning, TEXT("Server: SpawnLocaton: %s"), *ProjectileSpawnLocation.ToString());

        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("SpawnLocaton: %s"), *ProjectileSpawnLocation.ToString());

        }

        NewProjectile->Initialize(ProjectileWeaponConfigData);
        NewProjectile->Launch();    

    }
}