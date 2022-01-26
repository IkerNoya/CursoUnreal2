// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemStruct.h"
#include "SlotStructure.generated.h"

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FSlotStructure
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Item)
	FItemStruct ItemStruct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 Quantity;

	FSlotStructure()
	{
		Quantity=0;
	}
};
