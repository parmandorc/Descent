// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Descent.h"
#include "DescentProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

ADescentProjectile::ADescentProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ADescentProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

  // Remove projectile shadow for point light to move through the projectile object.
  CollisionComp->SetCastShadow(false);

	// Set as root component
	RootComponent = CollisionComp;

  // Create a PointLight component, set the colour, the brightness (lumens) and attach it the the root component.
  PointLightComp = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComp"));
  FLinearColor fireRed(1, 0.4f, 0);
  PointLightComp->SetLightColor(fireRed);
  PointLightComp->SetIntensity(10000.0f);
  PointLightComp->SetupAttachment(CollisionComp);


	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
  ProjectileMovement->ProjectileGravityScale = 0.0f;

	// Die after 3 seconds by default
	InitialLifeSpan = 10.0f;
}

void ADescentProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}
}