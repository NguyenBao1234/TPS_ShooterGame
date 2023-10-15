// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterEnemyController.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "ShooterCharacter.h"
void AShooterEnemyController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
}

bool AShooterEnemyController::isEnemyAlive()
{
	AShooterCharacter* ShooterChar = Cast<AShooterCharacter>(GetPawn());
	if (ShooterChar)
	{
		return ShooterChar->isAlive();
	}
	return true;
}

void AShooterEnemyController::BeginPlay()
{
	Super::BeginPlay();
	if (BehaviorTreeAsset)
	{
		RunBehaviorTree(BehaviorTreeAsset);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StandLocation"), GetPawn()->GetActorLocation());
	}
}
