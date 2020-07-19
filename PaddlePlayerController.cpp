 // Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Padle.h"
#include "Ball.h"


APaddlePlayerController::APaddlePlayerController() {
    
}

void APaddlePlayerController::BeginPlay()
{
    TArray<AActor*> CameraActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

    FViewTargetTransitionParams Params;
    SetViewTarget(CameraActors[0], Params);

    //��ProjectileMovement����Impluse��������С��Ĳ�������Launch������
    //SpawnNewBall();

    MyPawn = Cast<APadle>(GetPawn());
}


//�������Ӧ��Ҳ������Ϸ��ʼ�ĳ��ڱ�ִ�У����ڰ�����ִ�к���
void APaddlePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    EnableInput(this);

    InputComponent->BindAxis("MoveRight", this, &APaddlePlayerController::MoveHorizontal);
    InputComponent->BindAction("Launch", IE_Pressed, this, &APaddlePlayerController::launch);
}

void APaddlePlayerController::MoveHorizontal(float Value)
{
    //auto MyPawn = Cast<APadle>(GetPawn());
    if (MyPawn) {
        MyPawn->MoveHorizontal(Value);
    }
}

void APaddlePlayerController::launch()
{
    SpawnNewBall();
    MyBall->launch();
}

void APaddlePlayerController::SpawnNewBall()
{
    if (!MyBall) {
        MyBall = nullptr;
    }
    if (BallObj) {
        MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator, SPawnInfo);
    }
}
