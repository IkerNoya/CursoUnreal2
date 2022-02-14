// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest/FQuestStruct.h"
#include "ObjectiveBase.generated.h"

UCLASS(DefaultToInstanced,EditInlineNew,BlueprintType, Blueprintable)
class CURSOUNREAL2_API UObjectiveBase : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FString Description;
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objective)
	bool bIsCompleted = false;

	virtual void CheckData(FQuestCheckList CheckList){}
		
};
