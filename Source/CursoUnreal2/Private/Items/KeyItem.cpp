// Copyright Iker Noya 2022.


#include "Items/KeyItem.h"

#include "Inventory/InventoryComponent.h"

void UKeyItem::Use(AMainPlayer* Player)
{
	Super::Use(Player);
	OwningInventory->ItemEquipped = this;
}
