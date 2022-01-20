// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "DoorComponentBase.h"
#include "DoorWithKeyComponent.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API UDoorWithKeyComponent : public UDoorComponentBase
{
	GENERATED_BODY()
	
protected:
virtual void BeginPlay() override;
public:
	
};
