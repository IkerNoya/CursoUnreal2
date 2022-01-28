// Copyright Iker Noya 2022.


#include "EscapeRoom/Doors/KeyDoor.h"
#include "Items/Item.h"

void AKeyDoor::BeginPlay()
{
	Super::BeginPlay();
	APawn* Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (Pawn)
	{
		Player = Cast<AMainPlayer>(Pawn);
		if (!Player)
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't Find Player"));
		}
	}
}

AKeyDoor::AKeyDoor()
{
	bIsDoorLocked = true;
}

//TODO: Buscar forma de separar responsabilidades mas adelante

void AKeyDoor::HandleInteraction()
{
	IInteractionInterface::HandleInteraction();
	UItem* UsedItem = Player->Inventory->ItemEquipped;
	if (UsedItem && KeyToOpen)
	{
		if (UsedItem->StaticClass() == KeyToOpen->StaticClass() && bIsDoorLocked)
		{
			Unlock();
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Removed Key from inventory"));
			UsedItem->ConditionalBeginDestroy();
			Player->Inventory->RemoveAndDeleteItem(UsedItem);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Can't use Item Here"));
			Player->Inventory->ItemEquipped=nullptr;
			return;
		}
	}
	TryInteractWithDoor();
}
