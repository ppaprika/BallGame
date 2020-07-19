// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <Engine/World.h>
#include "PaddlePlayerController.generated.h"

/**
 * 
 */

class ABall;

UCLASS()
class BALLGAME_API APaddlePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APaddlePlayerController();

	UFUNCTION()
	virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;

	void MoveHorizontal(float Value);

	class APadle* MyPawn;

	void launch();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABall> BallObj;

	ABall* MyBall;

	FVector SpawnLocation = FVector(300.0f, 100.0f, 640.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SPawnInfo;

public:
	void SpawnNewBall();


};
