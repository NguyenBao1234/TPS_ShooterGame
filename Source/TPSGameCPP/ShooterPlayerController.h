// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TPSGAMECPP_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	/** Pawn has been possessed, so changing state to NAME_Playing. Start it walking and begin playing with it. */
	virtual void BeginPlay()override;

public:
	//~ Begin AController Interface
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
	UPROPERTY(EditAnywhere)
		float DelayRestart = 4;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> WidgetLoseScreenClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> WidgetWinScreenClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> WidgetHUDClass;
    
	UUserWidget* HUDWidget;
};
