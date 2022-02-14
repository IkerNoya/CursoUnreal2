// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ObjectiveBase.h"
#include "Items/ItemBase.h"
#include "PickUpObjective.generated.h"

UCLASS()
class CURSOUNREAL2_API UPickUpObjective : public UObjectiveBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	TSubclassOf<AItemBase> PickedUpItem;

public:
	virtual void CheckData(FQuestCheckList CheckList) override;
	
};
