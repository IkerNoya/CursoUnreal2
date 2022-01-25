// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemStruct.generated.h"

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FItemStruct
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	FName Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	bool bIsStackable;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	UTexture2D* Image;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	FString Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	bool bIsConsumable;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	int32 MaxStackSize;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Item)
	AItemBase* Item;

	FItemStruct()
	{
		Name = "None";
		bIsStackable = false;
		Image = nullptr;
		Description = "No item description";
		bIsConsumable = false;
		MaxStackSize = 0;
		Item = nullptr;
	}
};
