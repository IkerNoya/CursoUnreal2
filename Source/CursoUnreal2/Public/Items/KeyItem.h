// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "KeyItem.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API UKeyItem : public UItem
{
	GENERATED_BODY()

public:
	virtual void Use(AMainPlayer* Player) override;
};
