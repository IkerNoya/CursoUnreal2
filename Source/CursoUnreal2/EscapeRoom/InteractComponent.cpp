// Copyright Iker Noya 2022.


#include "InteractComponent.h"

#include "InteractionInterface.h"
#include "ToolContextInterfaces.h"
#include "CursoUnreal2/QuestInterface.h"
#include "Items/Item.h"
#include "Quest/ObjectivePickup.h"

#define ECC_Interactable          ECC_GameTraceChannel1

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractComponent::FindPlayerLocationAndRotation()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerLocation, PlayerRotation);
}

FVector UInteractComponent::CalculateLineTraceEnd()
{
	return PlayerLocation + (PlayerRotation.Vector() * InteractDistance);
}


void UInteractComponent::Interact()
{
	FHitResult Hit;
	FindPlayerLocationAndRotation();
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	if (GetWorld()->LineTraceSingleByObjectType(Hit, PlayerLocation, CalculateLineTraceEnd(),
	                                            FCollisionObjectQueryParams(ECC_Interactable),
	                                            TraceParams))
	{
		AActor* Actor = Hit.GetActor();
		if (Actor)
		{
			IInteractionInterface* InteractionObject = Cast<IInteractionInterface>(Actor);
			UActorComponent* ObjectiveObject = Actor->GetComponentByClass(UObjectivePickup::StaticClass());
			if(ObjectiveObject)
			{
				IQuestInterface* QuestInterface = Cast<IQuestInterface>(ObjectiveObject);
				if(QuestInterface)
				{
					QuestInterface->OnPickup();
					UE_LOG(LogTemp, Display, TEXT("SOY OBJETIVO"));
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("NO HAY OBJETIVO PA"));
				}
			}

			if(InteractionObject)
			{
				InteractionObject->HandleInteraction();
			}
		}
	}
}
