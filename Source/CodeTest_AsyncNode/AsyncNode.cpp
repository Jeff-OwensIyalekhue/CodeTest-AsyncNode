// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncNode.h"

void UAsyncNode::Activate()
{
    ATargetActor* target = const_cast<ATargetActor*>(targetActor);
    target->OnTargetBooleanChanged.AddDynamic(this, &UAsyncNode::ExecuteOnBooleanChanged);
}

UAsyncNode* UAsyncNode::WaitForBooleanChange(const UObject* WorldContextObject, const AActor* listenActor, const ATargetActor* targetActor)
{
    UAsyncNode* BlueprintNode = NewObject<UAsyncNode>();
    BlueprintNode->WorldContextObject = WorldContextObject;
    BlueprintNode->listenActor = listenActor;
    BlueprintNode->targetActor = targetActor;
    BlueprintNode->RegisterWithGameInstance(WorldContextObject);
    return BlueprintNode;
}

void UAsyncNode::ExecuteOnBooleanChanged(bool NewValue)
{
    OnValueChange.Broadcast(NewValue);
    SetReadyToDestroy();
}