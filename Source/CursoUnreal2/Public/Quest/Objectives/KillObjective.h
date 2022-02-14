// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ObjectiveBase.h"
#include "KillObjective.generated.h"

UCLASS()
class CURSOUNREAL2_API UKillObjective : public UObjectiveBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective, meta = (ClampMin=1))
	int KillsNeeded=1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=ID_OBJECTIVE_SIZE, meta = (ClampMin = 0))
	int CurrentKills=0;
public:
	virtual void CheckData(FQuestCheckList CheckList) override;
};
