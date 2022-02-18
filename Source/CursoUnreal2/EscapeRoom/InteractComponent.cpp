// Copyright Iker Noya 2022.


#include "InteractComponent.h"

#include "InteractionInterface.h"
#include "ToolContextInterfaces.h"
#include "Items/Item.h"

#define ECC_Interactable          ECC_GameTraceChannel1
#define ECC_Pickable              ECC_GameTraceChannel3

void UInteractComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	SendInteractedObject.Clear();
	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

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
	FCollisionObjectQueryParams ObjectParams = FCollisionObjectQueryParams(
		ECC_TO_BITFIELD(ECC_Interactable) | ECC_TO_BITFIELD(ECC_Pickable));
	if (GetWorld()->LineTraceSingleByObjectType(Hit, PlayerLocation, CalculateLineTraceEnd(),
	                                            ObjectParams,
	                                            TraceParams))
	{
		AActor* Actor = Hit.GetActor();
		if (Actor)
		{
			IInteractionInterface* InteractionObject = Cast<IInteractionInterface>(Actor);
			AItemBase* ItemActor = nullptr;
	
			switch (Hit.Component->GetCollisionObjectType())
			{
			case ECC_Interactable:
				if (InteractionObject)
				{
					SendInteractedObject.Broadcast(Actor->GetClass());
					InteractionObject->HandleInteraction();
				}
				break;
			case ECC_Pickable:
				ItemActor = Cast<AItemBase>(Actor);
				if (ItemActor && InteractionObject)
				{
					SendInteractedObject.Broadcast(Actor->GetClass());
					if(ItemActor->Item)
					{
						SendPickableObject.Broadcast(ItemActor->Item);
						Actor->Destroy();
					}
					else
					{
						UE_LOG(LogTemp, Error, TEXT("Item in % is null"), *ItemActor->GetName())
					}
				}
				break;
			default:
				UE_LOG(LogTemp, Error, TEXT("Wrong collision profile in Interacted object"));
				break;
			}
		}
	}
}
