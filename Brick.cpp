// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	//Box_Collision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));
	//RootComponent = Box_Collision;
	
	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	RootComponent = SM_Brick;
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	//Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
	
}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//ͨ���鿴��ǩȷ��Actor���ͣ��ܲ���ֱ��Castȷ����������ͼ����������
	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);
		//��һ���Ǹ�ʲô�ģ���
		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);
		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);
		DestroyBrick();
	
	}
}

void ABrick::DestroyBrick()
{
	this->Destroy();
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

