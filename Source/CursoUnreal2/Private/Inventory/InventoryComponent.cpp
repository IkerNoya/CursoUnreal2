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
	InteractComponent = GetOwner()->FindComponentByClass<UInteractComponent>();
	for (auto& Item : DefaultItems)
	{
		AddItem(Item);
	}
	if (InteractComponent)
	{
		InteractComponent->SendPickableObject.AddDynamic(this, &UInventoryComponent::AddBlueprintItem);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't find Interact component in %s"), *GetName())
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

void UInventoryComponent::AddBlueprintItem(TSubclassOf<UItem> Item)
{
	if (Items.Num() >= Capacity || !Item)
	{
		return;
	}
	UItem* NewItem = NewObject<UItem>(this, Item);
	if(NewItem)
	{
		NewItem->OwningInventory=this;
		NewItem->World = GetWorld();
		Items.Add(NewItem);
	}
}

bool UInventoryComponent::RemoveItem(UItem* Item)
{
	if (Item)
	{
		Item->SpawnActor(GetOwner()->GetActorLocation() + DropOffset);
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		if (ItemEquipped == Item)
		{
			ItemEquipped = nullptr;
		}
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}

bool UInventoryComponent::RemoveAndDeleteItem(UItem* Item)
{
	if (Item)
	{
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		if (ItemEquipped == Item)
		{
			ItemEquipped = nullptr;
		}
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}
