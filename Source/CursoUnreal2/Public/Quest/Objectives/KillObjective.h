// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ObjectiveBase.h"
#include "KillObjective.generated.h"

UCLASS()
class CURSOUNREAL2_API UKillObjective : public UObjectiveBase
{
	GENERATED_BODY()

public:
	virtual void CheckData(FQuestCheckList CheckList) override;
};
