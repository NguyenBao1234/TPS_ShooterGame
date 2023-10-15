// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "GameFrameWork/Controller.h"
#include "EngineUtils.h"
#include "ShooterEnemyController.h"


void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	APlayerController* ShooterPlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (ShooterPlayerController)
	{
		//PlayerController chi co o player thoi nen Neu PawnKill la Co chua PlayerController thi Player bi tieu diet
		GameEndWithWin(false);
		return;
	}
	else
	{
		for (AShooterEnemyController* ControllerElementInLevel : TActorRange<AShooterEnemyController>(GetWorld()))
		{
		/*Boi vi Controller can phai goi GameHasEnd truoc khi Pawn tach khoi va xoa Controller nen khi ham nay xay ra van con Controller
		* Vi the khong the kiem tra bang viec AI Enemy chet chua qua !Controller duoc, vi the con tao them ham de lay thong tin
		*/
			if (ControllerElementInLevel->isEnemyAlive())
			{
				return;
			}
			/*Neu van con Enemy thi ket thuc tu day vi co return, du co bao nhieu AIController di nua
			* thi van se dung ngay khi gap AI dau tien, nghia la khong phai lap lai code lan nao ca
			*/
		}
	}
	GameEndWithWin(true);

	UE_LOG(LogTemp, Warning, TEXT("Nguoi choi thang"))
}

void AKillEmAllGameMode::GameEndWithWin(bool bPlayerAlive)
{
	/*De goi duoc GameHasEnded() thi phai goi tu controller vi the ta can lay tung controller ngoai the gioi
	* do da xu ly cac truong hop khi 1 shooter bi tieu diet o ham PawnKilled roi nen ham nay ta chi can truyen bien
	* Doi voi cac AIcontroller khi goi GameHasEnded() se khong anh huong den game
	* vi toi moi chi ghi de trong ShooterPlayerController.h
	*/
	for (AController* ControllerElementInLevel : TActorRange<AController>(GetWorld()))
	{
		ControllerElementInLevel->GameHasEnded(ControllerElementInLevel->GetPawn(), bPlayerAlive);
	}

	
}
