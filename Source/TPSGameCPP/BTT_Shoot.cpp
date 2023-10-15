// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Shoot.h"
#include "AIController.h"
#include "ShooterCharacter.h"

EBTNodeResult::Type UBTT_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AShooterCharacter* ShooterCharActorAI = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	ShooterCharActorAI->Shoot();

	return EBTNodeResult::Succeeded;
}

UBTT_Shoot::UBTT_Shoot()
{
	NodeName = "ShootFromPawnShooter";
}
