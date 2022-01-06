// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSe.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"

UBTService_PlayerLocationIfSe::UBTService_PlayerLocationIfSe() 
{
    NodeName = "Update Player Location If Seen";
}

void UBTService_PlayerLocationIfSe::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) 
{
        APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if (PlayerPawn == nullptr)
    {
        return;
    }
    
    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return;
    }
    
    if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
    

}
