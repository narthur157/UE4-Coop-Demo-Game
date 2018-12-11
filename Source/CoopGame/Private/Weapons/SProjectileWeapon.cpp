#include "SProjectileWeapon.h"
#include "SProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Engine/World.h"   
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"

void ASProjectileWeapon::Fire()
{
    LastFireTime = GetWorld()->TimeSeconds;
    UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	AmmoInClip--;

    if (Role < ROLE_Authority)
    {
        ServerFire();
        return;
    }

    if (ProjectileClass && GetOwner())
    {
        FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleEffect, MuzzleLocation);
        FRotator ProjectileSpawnRotation;
        FVector OutViewPointLocation;
        GetOwner()->GetActorEyesViewPoint(OutViewPointLocation, ProjectileSpawnRotation);

		OutViewPointLocation += ProjectileSpawnRotation.Vector() * ProjectileSpawnOffset;

		// uncomment to debug projectile spawn
		// DrawDebugSphere(GetWorld(), OutViewPointLocation, 5, 12, FColor::Red, false, 5.0f);

        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        SpawnParams.Instigator = Cast<APawn>(GetOwner());
        SpawnParams.Owner = this;
        ASProjectile* NewProjectile = GetWorld()->SpawnActor<ASProjectile>(ProjectileClass, OutViewPointLocation, ProjectileSpawnRotation, SpawnParams);

        NewProjectile->Initialize(ProjectileWeaponConfigData);
        NewProjectile->Launch();
    }
}

void ASProjectileWeapon::SpawnProjectile(TSubclassOf<ASProjectile> Projectile)
{

}
