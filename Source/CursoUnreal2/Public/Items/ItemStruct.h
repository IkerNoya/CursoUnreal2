// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ItemStruct.generated.h"

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FItemStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	bool bIsStackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	UTexture2D* Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	bool bIsConsumable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 MaxStackSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (ClampMin = 0.0))
	float Weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Item)
	class UInventoryComponent* OwningInventory;

	FItemStruct()
	{
		Name = "None";
		bIsStackable = false;
		Image = nullptr;
		Description = "No item description";
		bIsConsumable = false;
		MaxStackSize = 0;
		Weight = 0;
		OwningInventory = nullptr;
		// Item = nullptr;
	}
};
