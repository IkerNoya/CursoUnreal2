// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActivationInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UActivationInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CURSOUNREAL2_API IActivationInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION()
	virtual void ActivateActor(){}
};
