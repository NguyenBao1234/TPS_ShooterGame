// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class TPSGAMECPP_API AShooterEnemyController : public AAIController
{
	GENERATED_BODY()
public:

	virtual void Tick(float Deltatime) override;

	bool isEnemyAlive();

protected:

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		UBehaviorTree* BehaviorTreeAsset;
};
