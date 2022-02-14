// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest/QuestCheckList.h"
#include "ObjectiveBase.generated.h"

UCLASS(DefaultToInstanced,EditInlineNew,BlueprintType, Blueprintable)
class CURSOUNREAL2_API UObjectiveBase : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective, meta = (ClampMin=0))
	int32 CurrentProgress=0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective, meta = (ClampMin=1))
	int32 ProgressNeededToComplete=1;
	
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objective)
	bool bIsCompleted = false;

	virtual void CheckData(FQuestCheckList CheckList){}
		
};
