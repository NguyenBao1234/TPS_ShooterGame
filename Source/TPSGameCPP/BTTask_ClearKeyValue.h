// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ClearKeyValue.generated.h"

/**
 * 
 */
UCLASS()
class TPSGAMECPP_API UBTTask_ClearKeyValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;
public:
	UBTTask_ClearKeyValue();
};
