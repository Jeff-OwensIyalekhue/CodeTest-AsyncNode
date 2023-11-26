// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "TargetActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTargetEventDelegate, bool, bNewValue);

UCLASS()
class CODETEST_ASYNCNODE_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetActor();

	UPROPERTY(BlueprintAssignable, Category = "TargetActor")
	FTargetEventDelegate OnTargetBooleanChanged;

	UPROPERTY(ReplicatedUsing = OnRep_IsListenerToBeDestroyed, EditAnywhere, Category = "TargetActor")
	bool bIsListenerToBeDestroyed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "TargetActor")
	void SetListenerToBeDestroyed(bool NewValue);

	UFUNCTION()
	void OnRep_IsListenerToBeDestroyed();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
};
