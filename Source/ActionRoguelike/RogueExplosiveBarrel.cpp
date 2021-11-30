// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueExplosiveBarrel.h"

#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ARogueExplosiveBarrel::ARogueExplosiveBarrel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	StaticMesh->SetSimulatePhysics(true);
	StaticMesh->SetCollisionProfileName("PhysicsActor");
	
	RadialForce = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForce"));
}

// Called when the game starts or when spawned
void ARogueExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh->OnComponentHit.AddDynamic(this, &ARogueExplosiveBarrel::OnHit);
}

// Called every frame
void ARogueExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARogueExplosiveBarrel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForce->FireImpulse();
}

