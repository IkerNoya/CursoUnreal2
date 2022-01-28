// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class CURSOUNREAL2_API	UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	FVector DropOffset = FVector::ZeroVector;
	
public:
	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<class UItem*> DefaultItems;
	UPROPERTY(EditDefaultsOnly, Category=Inventory)
	int32 Capacity;
	UPROPERTY(BlueprintAssignable, Category=Inventory)
	FOnInventoryUpdated OnInventoryUpdated;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Items)
	TArray<class UItem*> Items;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Items)
	class UItem* ItemEquipped = nullptr;
	
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	bool AddItem(class UItem* Item);
	
	UFUNCTION(BlueprintCallable)
	bool RemoveItem(class UItem* Item);
	UFUNCTION(BlueprintCallable)
	bool RemoveAndDeleteItem(class UItem* Item);
};
