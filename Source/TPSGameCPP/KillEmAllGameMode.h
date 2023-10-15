// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TPSGAMECPP_API AKillEmAllGameMode : public AShooterGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* PawnKilled)override;

private:

	//Xu ly moi khi co 1 Shooter bi tieu diet, neu chua du dieu kien thang Ham se truyen bien false vao GameHasEnd
	void GameEndWithWin(bool bPlayerAlive);
};
