// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = SM_Ball;
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 5.0f;
	ProjectileMovement->Friction = 0.0f;
	//教程里这里设置的是x
	ProjectileMovement->Velocity.Y = 0.0f;
	//ProjectileMovement->InitialSpeed = 500;

}


// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::launch()
{
	if (!bBallLaunched) {
		//SM_Ball->AddImpulse(FVector(560.0f, 0.0f, 520.0f), FName(), true);
		ProjectileMovement->InitialSpeed = 500;
		bBallLaunched = true;
	}
}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}

