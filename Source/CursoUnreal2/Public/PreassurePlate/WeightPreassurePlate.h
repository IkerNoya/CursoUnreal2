// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "CursoUnreal2/EscapeRoom/DoorBase.h"
#include "PreassurePlate/PreassurePlateBase.h"
#include "WeightPreassurePlate.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API AWeightPreassurePlate : public APreassurePlateBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	float MassToActivate=50.f;
	UPROPERTY()
	ADoorBase* Door;

	virtual void BeginPlay() override;
	
	virtual void HandleInteraction() override;
	
private:
	bool IsMassEnoughToActivate();
	
};
