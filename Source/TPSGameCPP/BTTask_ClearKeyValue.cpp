// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearKeyValue.h"
#include "BehaviorTree/BlackBoardComponent.h"

EBTNodeResult::Type UBTTask_ClearKeyValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}

UBTTask_ClearKeyValue::UBTTask_ClearKeyValue()
{
	NodeName = "Clear Key Value";
}
