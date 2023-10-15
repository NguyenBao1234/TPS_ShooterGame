// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_LastPointPlayer.generated.h"

/**
 * 
 */
UCLASS()
class TPSGAMECPP_API UBTService_LastPointPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_LastPointPlayer();
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
