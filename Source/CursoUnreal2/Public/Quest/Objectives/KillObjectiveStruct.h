// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ObjectiveStruct.h"
#include "KillObjectiveStruct.generated.h"

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FKillObjectiveStruct : public FObjectiveStruct
{
	GENERATED_BODY()


	virtual void CheckData(FQuestCheckList List) override;
};
