// Copyright Iker Noya 2022.


#include "Quest/Tasks/InteractionTask.h"

void UInteractionTask::SetDelegates()
{
	Super::SetDelegates();
	if(InteractComponent)
	{
		InteractComponent->SendInteractedObject.AddDynamic(this, &UInteractionTask::GetInteractedObject);
	}
}

void UInteractionTask::InitializeVariables()
{
	Super::InitializeVariables();
	InteractComponent = Cast<UInteractComponent>(Player->GetComponentByClass(UInteractComponent::StaticClass()));
	if (!InteractComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't find InteractComponent in class %s"), *GetName())
	}
}

void UInteractionTask::BeginDestroy()
{
	Super::BeginDestroy();
}

void UInteractionTask::GetInteractedObject(TSubclassOf<AActor> InteractedObject)
{
	if (InteractedObject)
	{
		CheckList.InteractedObject = InteractedObject;
		SendData.Broadcast(CheckList);
	}
}
