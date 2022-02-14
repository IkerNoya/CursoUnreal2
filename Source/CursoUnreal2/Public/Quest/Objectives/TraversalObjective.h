// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ObjectiveBase.h"
#include "TraversalObjective.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API UTraversalObjective : public UObjectiveBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective, meta = (ClampMin = 1.0));
	float DistanceToTravel = 1.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objective);
	float DistanceTraveled = 0.f;

public:
	virtual void CheckData(FQuestCheckList CheckList) override;
};
