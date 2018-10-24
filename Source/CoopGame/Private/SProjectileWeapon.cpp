// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"
#include "SProjectile.h"
#include "Engine/World.h"
#include "Components/SkeletalMeshComponent.h"


void ASProjectileWeapon::Fire()
{

    if (ProjectileClass && GetOwner())
    {
        FVector ProjectileSpawnLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
        FRotator ProjectileSpawnRotation;

        FVector OutViewPointLocation;
        GetOwner()->GetActorEyesViewPoint(OutViewPointLocation, ProjectileSpawnRotation);

        ProjectileSpawnRotation = ProjectileSpawnRotation;
        FActorSpawnParameters SpawnParams;
        SpawnParams.Instigator = Cast<APawn>(GetOwner());
        ASProjectile* NewProjectile = GetWorld()->SpawnActor<ASProjectile>(ProjectileClass, ProjectileSpawnLocation, ProjectileSpawnRotation, SpawnParams);
        UE_LOG(LogTemp, Warning, TEXT("MadeIt"));
        NewProjectile->Initialize(ProjectileWeaponConfigData);
        NewProjectile->Launch();
    }
}