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

	ExplosionStatus.bExploded = false;
	ExplosionStatus.bWasDirectPawnHit = false;

    SetReplicates(true);
	SetReplicateMovement(true);
}

void ASProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASProjectile, ExplosionStatus);
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

    OnActorHit.AddDynamic(this, &ASProjectile::OnProjectileHit);

    if (WeaponData.DoesExpire())
    {
        GetWorld()->GetTimerManager().SetTimer(FuseTimerHandle, this, &ASProjectile::OnProjectileExpire, WeaponData.ProjectileLifeTime, false);
    }
}

void ASProjectile::OnProjectileExpire()
{
    ExplosionStatus.bExploded = true;

	if (Role == ROLE_Authority)
	{
		OnRep_Exploded();
	}
}

void ASProjectile::OnProjectileHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
	if (OtherActor == Instigator)
	{
		return;
	}

	FProjectileExplosion NewStatus;
	DirectHitActor = OtherActor;
	
	if (Cast<APawn>(OtherActor))
	{
		NewStatus.bWasDirectPawnHit = true;
	}

	NewStatus.bExploded = true;
	ExplosionStatus = NewStatus;
    
	GetWorld()->GetTimerManager().ClearTimer(FuseTimerHandle);

	if (Role == ROLE_Authority)
	{
	    OnRep_Exploded();
	}
}

void ASProjectile::DirectHit()
{
	AController* InstContr = GetInstigatorController();

	// directly hitting an explosive barrel, for example, doesn't warrant a special sound
	if (ExplosionStatus.bWasDirectPawnHit && DirectHitSoundEffect)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), DirectHitSoundEffect);
	}

	if (Role == ROLE_Authority && DirectHitActor)
	{
		float DirectDamage = ApplyDamageModifier(WeaponData.ProjectileDamageDirectHit);

		UGameplayStatics::ApplyDamage(DirectHitActor, DirectDamage,
			Instigator->GetController(), GetOwner(), WeaponData.ProjectileDamageType);
	}
}

float ASProjectile::ApplyDamageModifier(float Damage)
{
	IDamageDealer* DamageDealer = Cast<IDamageDealer>(GetInstigator());
	
	return DamageDealer ? Damage += (DamageDealer->GetDamageModifier() / 100) * Damage : Damage;
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

	DirectHit();

    // TODO: Find a way to remove this, calculate ignored actors in projectileweapondata?
    TArray<AActor*> IgnoredActors = { this, GetOwner(), Instigator };
    if (Role == ROLE_Authority)
    {

        float ActualDamageRadial = ApplyDamageModifier(WeaponData.ProjectileDamage);
		
		bool HitSomething = UGameplayStatics::ApplyRadialDamage(GetWorld(), ActualDamageRadial,
			GetActorLocation(), WeaponData.ProjectileRadius, WeaponData.ProjectileDamageType,
			IgnoredActors, GetOwner(), Instigator->GetController(), true);

		ASWeapon* MyOwner = Cast<ASWeapon>(GetOwner());

		if (HitSomething && MyOwner)
		{
			MyOwner->OnHit(nullptr, true);
		}

		SetLifeSpan(0.5f);
	}

	MeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
    SetActorHiddenInGame(true);
}

void ASProjectile::OnRep_Exploded()
{
    Explode();
}