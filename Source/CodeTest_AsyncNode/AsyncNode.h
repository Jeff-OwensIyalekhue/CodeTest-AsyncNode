// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TargetActor.h"
#include "AsyncNode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBooleanChangedDelegate, bool, bNewValue);

UCLASS()
class CODETEST_ASYNCNODE_API UAsyncNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "DetectActorBooleanAsyncNode")
	FBooleanChangedDelegate OnValueChange;

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInteralUseOnly = "true", WorldContext = "WorldContextObject", DefaultToSelf = "listenActor"), Category = "AsyncNode")
	static UAsyncNode* WaitForBooleanChange(const UObject* WorldContextObject, const AActor* listenActor, const ATargetActor* targetActor);

	UFUNCTION()
	void ExecuteOnBooleanChanged(bool NewValue);

	const UObject* WorldContextObject;
	const AActor* listenActor;
	const ATargetActor* targetActor;
};
