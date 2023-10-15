// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_LocationSeenPlayer.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackBoardComponent.h"

void UBTService_LocationSeenPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	
	if (!PlayerPawn||!OwnerComp.GetAIOwner()->GetPawn()) return;
	if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
	
}

UBTService_LocationSeenPlayer::UBTService_LocationSeenPlayer()
{
	NodeName = "Update location PLayer if seen";
}
