// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"




// Sets default values
ARogueMagicProjectile::ARogueMagicProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComponent->SetCollisionProfileName("Projectile");
	RootComponent = SphereComponent;

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EffectComp"));
	ParticleSystemComponent->SetupAttachment(RootComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComp"));
	ProjectileMovementComponent->InitialSpeed = 1000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bInitialVelocityInLocalSpace = true;

}

// Called when the game starts or when spawned
void ARogueMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARogueMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

