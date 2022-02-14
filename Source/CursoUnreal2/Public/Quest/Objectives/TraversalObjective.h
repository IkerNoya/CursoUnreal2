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

public:
	virtual void CheckData(FQuestCheckList CheckList) override;
};
