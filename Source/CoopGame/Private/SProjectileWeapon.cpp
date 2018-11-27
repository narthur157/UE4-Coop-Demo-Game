// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"
#include "SProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Engine/World.h"   
#include "Components/SkeletalMeshComponent.h"

ASProjectileWeapon::ASProjectileWeapon()
{
	ProjectileSpawnTranslate = FVector(100.0f, 0, 0);
}

void ASProjectileWeapon::Fire()
{
    LastFireTime = GetWorld()->TimeSeconds;
    UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());

    if (Role < ROLE_Authority)
    {
        ServerFire();
        return;
    }

	AmmoInClip--;

    if (ProjectileClass && GetOwner())
    {
        FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleEffect, MuzzleLocation);
        FRotator ProjectileSpawnRotation;
        FVector OutViewPointLocation;
        GetOwner()->GetActorEyesViewPoint(OutViewPointLocation, ProjectileSpawnRotation);

		OutViewPointLocation += ProjectileSpawnRotation.Vector() * ProjectileSpawnTranslate;

        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        SpawnParams.Instigator = Cast<APawn>(GetOwner());
        SpawnParams.Owner = this;
        ASProjectile* NewProjectile = GetWorld()->SpawnActor<ASProjectile>(ProjectileClass, OutViewPointLocation, ProjectileSpawnRotation, SpawnParams);

        NewProjectile->Initialize(ProjectileWeaponConfigData);
        NewProjectile->Launch();
    }
}