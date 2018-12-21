#include "SProjectileWeapon.h"
#include "SProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Engine/World.h"   
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"


void ASProjectileWeapon::SpawnPredictedProjectile(TSubclassOf<ASProjectile> Projectile,  bool bDoDamage)
{
    if (Projectile && GetOwner())
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

        NewProjectile->Initialize(ProjectileWeaponConfigData, (HasAuthority() && GetInstigator()->IsPlayerControlled()));
        NewProjectile->Launch();
    }
}
