// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class CURSOUNREAL2_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<class UItem*> DefaultItems;
	UPROPERTY(EditDefaultsOnly, Category=Inventory)
	int32 Capacity;
	UPROPERTY(BlueprintAssignable, Category=Inventory)
	FOnInventoryUpdated OnInventoryUpdated;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Items)
	TArray<class UItem*> Items;
	
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	bool AddItem(class UItem* Item);
	bool RemoveItem(class UItem* Item);
};
