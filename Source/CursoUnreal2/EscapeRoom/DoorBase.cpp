// Copyright Iker Noya 2022.


#include "DoorBase.h"

ADoorBase::ADoorBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADoorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

