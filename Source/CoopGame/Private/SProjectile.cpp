// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ASProjectile::ASProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
    MovementComp->SetAutoActivate(false);
    MovementComp->bAutoActivate = false;

}

// Called when the game starts or when spawned
void ASProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASProjectile::Launch(float LaunchSpeed)
{
    MovementComp->InitialSpeed = LaunchSpeed;
    MovementComp->Activate();
}