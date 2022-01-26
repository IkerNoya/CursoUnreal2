// Copyright Iker Noya 2022.


#include "Items/KeyItem.h"

void UKeyItem::Use(AMainPlayer* Player)
{
	Super::Use(Player);
	UE_LOG(LogTemp, Warning, TEXT("USED KEY"));
}
