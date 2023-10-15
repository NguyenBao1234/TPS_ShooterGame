// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (WidgetHUDClass)
	{
	HUDWidget = CreateWidget(this,WidgetHUDClass);
	HUDWidget->AddToViewport();
	}
	

}
void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{

	Super::GameHasEnded(EndGameFocus, bIsWinner);
	if(HUDWidget) HUDWidget->RemoveFromParent();

	if (bIsWinner)
	{
		UUserWidget* WinWD = CreateWidget(this, WidgetWinScreenClass);
		if (WinWD) WinWD->AddToViewport(0);
	}
	else
	{
		UUserWidget* LoseWD = CreateWidget(this, WidgetLoseScreenClass);
		if (LoseWD)LoseWD->AddToViewport(0);
	}

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &APlayerController::RestartLevel, DelayRestart);
}
