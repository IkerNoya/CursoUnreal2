// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ElectricityInterface.generated.h"

UINTERFACE()
class UElectricityInterface : public UInterface
{
	GENERATED_BODY()
};

class CURSOUNREAL2_API IElectricityInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION()
	virtual void AddElectricity();
};
