// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FQuestStruct.h"
#include "Quest.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCheckQuestStatus, FName, QuestName);
UCLASS()
class CURSOUNREAL2_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FQuestStruct QuestData;

	UPROPERTY(BlueprintAssignable, Category = Quest)
	FCheckQuestStatus CheckQuestStatus;

	AQuest();

private:
	void CompleteQuest();

protected:
	virtual void BeginPlay() override;
public:
	void CompleteStepInObjective(int32 ObjectiveId);
	
	void CheckQuestCompletion();

};
