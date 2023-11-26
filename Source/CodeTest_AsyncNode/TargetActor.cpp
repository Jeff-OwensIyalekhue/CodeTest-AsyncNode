// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"

// Sets default values
ATargetActor::ATargetActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bIsListenerToBeDestroyed = false;
}


// Called when the game starts or when spawned
void ATargetActor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ATargetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATargetActor::SetListenerToBeDestroyed(bool NewValue)
{
	if (bIsListenerToBeDestroyed != NewValue)
	{
		bIsListenerToBeDestroyed = NewValue;
		OnTargetBooleanChanged.Broadcast(bIsListenerToBeDestroyed);
	}
}

void ATargetActor::OnRep_IsListenerToBeDestroyed()
{
	OnTargetBooleanChanged.Broadcast(bIsListenerToBeDestroyed);
}

void ATargetActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATargetActor, bIsListenerToBeDestroyed);
}

