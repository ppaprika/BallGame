// Fill out your copyright notice in the Description page of Project Settings.


#include "Padle.h"
#include "Components/StaticMeshComponent.h"
#include "GameFrameWork/FloatingPawnMovement.h"
#include "Components/SceneComponent.h"

// Sets default values
APadle::APadle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Padle"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SM_Paddle->SetupAttachment(RootComponent);


	SM_Paddle->SetEnableGravity(false);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	//这是干什么的？？？
	//如果关掉就没有碰撞了吗？？
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovement"));
}

// Called when the game starts or when spawned
void APadle::BeginPlay()
{
	Super::BeginPlay();
	//用于设置MovementComponent的UpdatedComponent
	UPawnMovementComponent* MovementComponent = GetMovementComponent();
	MovementComponent->SetUpdatedComponent(SM_Paddle);
}

// Called every frame
void APadle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APadle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//可以在Pawn里面绑定输入，但是我们这里将绑定到PaddlePlayerController上
	//PlayerInputComponent->BindAxis("MoveRight", this, &APadle::MoveHorizontal);
}

void APadle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);
}

