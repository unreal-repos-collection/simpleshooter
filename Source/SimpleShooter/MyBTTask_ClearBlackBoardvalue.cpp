// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_ClearBlackBoardvalue.h"
#include "BehaviorTree/BlackboardComponent.h"




UMyBTTask_ClearBlackBoardvalue::UMyBTTask_ClearBlackBoardvalue() 
{
    NodeName =  TEXT("Clear BlackBoard Value");
}

EBTNodeResult::Type UMyBTTask_ClearBlackBoardvalue::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) 
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

    return EBTNodeResult::Succeeded;
}


