#include "SProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "SProjectileWeapon.h"
#include "Sound/SoundCue.h"
#include "DamageDealer.h"
#include "Net/UnrealNetwork.h"
#include "SWeapon.h"

ASProjectile::ASProjectile()
{
    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    SetRootComponent(CollisionComp);

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComp->SetNotifyRigidBodyCollision(true);
    MeshComp->SetVisibility(true);
    MeshComp->SetupAttachment(CollisionComp);

    MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
    MovementComp->bAutoActivate = true;
    MovementComp->SetUpdatedComponent(CollisionComp);
	MovementComp->InitialSpeed = ProjectileSpeed;
	MovementComp->MaxSpeed = 5000.0f;

    SetReplicates(true);
	SetReplicateMovement(true);
}

void ASProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASProjectile, bExploded);
}

void ASProjectile::Initialize(const FProjectileWeaponData & Data)
{
    WeaponData = Data;
    bWasInitialized = true;
}

void ASProjectile::Launch()
{
    if (!bWasInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("Projectile fired despite not being Initialized. Please Initialze projectile. Undefined behavior incoming."))
    }

    // Register projectile to recieve hit events
    OnActorHit.AddDynamic(this, &ASProjectile::OnProjectileHit);

    // if the weapon has designated this projectile to expire, set a timer to do so
    if (WeaponData.DoesExpire())
    {
        GetWorld()->GetTimerManager().SetTimer(FuseTimerHandle, this, &ASProjectile::OnProjectileExpire, WeaponData.ProjectileLifeTime, false);
    }
}

void ASProjectile::OnProjectileExpire()
{
    bExploded = true;

	if (Role == ROLE_Authority)
	{
		OnRep_Exploded();
	}
}

void ASProjectile::OnProjectileHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
    bExploded = true;
    GetWorld()->GetTimerManager().ClearTimer(FuseTimerHandle);
    OnRep_Exploded();
}

void ASProjectile::Explode()
{
	GetWorld()->GetTimerManager().ClearTimer(FuseTimerHandle);

    if (ExplosionEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation(), FVector::ZeroVector.Rotation());
    }
    if (ExplosionSoundEffect)
    {
        UGameplayStatics::PlaySoundAtLocation(this, ExplosionSoundEffect, GetActorLocation());

    }

    // TODO: Find a way to remove this, calculate ignored actors in projectileweapondata?
    TArray<AActor*> IgnoredActors = { this, GetOwner(), Instigator };
    if (Role == ROLE_Authority)
    {

        IDamageDealer* DamageDealer = Cast<IDamageDealer>(GetInstigator());
        float ActualDamage = WeaponData.ProjectileDamage;
        
		if (DamageDealer)
        {
            ActualDamage += (DamageDealer->GetDamageModifier() / 100) * ActualDamage;
        }

		if (UGameplayStatics::ApplyRadialDamage(GetWorld(), WeaponData.ProjectileDamage, GetActorLocation(), WeaponData.ProjectileRadius, WeaponData.ProjectileDamageType, IgnoredActors, GetOwner(), Instigator->GetController(), true))
		{
			ASWeapon* MyOwner = Cast<ASWeapon>(GetOwner());
			if (MyOwner)
			{
				MyOwner->OnHit(nullptr, true);
			}
		}
    }

    SetActorHiddenInGame(true);
    if (Role == ROLE_Authority)
    {
        SetLifeSpan(5.0f);
    }
}

void ASProjectile::OnRep_Exploded()
{
    Explode();
}