// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_ClearBlackBoardvalue.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UMyBTTask_ClearBlackBoardvalue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	

public:
	UMyBTTask_ClearBlackBoardvalue();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override; 

};
