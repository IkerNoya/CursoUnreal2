// Copyright Iker Noya 2022.


#include "Items/Item.h"

UItem::UItem()
{
	
}

void UItem::Use(AMainPlayer* Player)
{
	UE_LOG(LogTemp, Warning, TEXT("EXAMPLE USE"));
}

void UItem::SpawnActor(FVector Position)
{
	if(ItemActor)
	{
		World->SpawnActor<AItemBase>(ItemActor,Position,FRotator::ZeroRotator, FActorSpawnParameters());
	}
}
