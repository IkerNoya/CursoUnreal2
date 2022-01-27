// Copyright Iker Noya 2022.


#include "Inventory/InventoryComponent.h"
#include "Items/Item.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	Capacity = 20;
}


void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item : DefaultItems)
	{
		UE_LOG(LogTemp, Warning, TEXT("ITEM NAME: %s"), *Item->GetName());
		AddItem(Item);
	}
}

bool UInventoryComponent::AddItem(UItem* Item)
{
	if (Items.Num() >= Capacity || !Item)
	{
		return false;
	}

	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);

	OnInventoryUpdated.Broadcast();
	return true;
}

bool UInventoryComponent::RemoveItem(UItem* Item)
{
	if(Item)
	{
		Item->SpawnActor(GetOwner()->GetActorLocation() + (GetOwner()->GetActorForwardVector() * 10));
		Item->OwningInventory=nullptr;
		Item->World=nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}
