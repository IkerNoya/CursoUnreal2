// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FQuestStruct.h"
#include "Quest.generated.h"

UENUM()
enum class EQuestState
{
	Inactive,
	Active,
	Completed,
	Failed
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCompleteQuest);

UCLASS()
class CURSOUNREAL2_API AQuest : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FQuestStruct QuestData;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Quest)
	EQuestState QuestState;

	AQuest();

private:
	void CompleteQuest();
	virtual void BeginDestroy() override;

protected:
	virtual void BeginPlay() override;
public:
	void CompleteStepInObjective(int32 ObjectiveId);

	void CheckQuestCompletion();

	EQuestState GetQuestState();
	void SetQuestState(EQuestState State);
	
	UPROPERTY(BlueprintAssignable)
	FOnCompleteQuest OnCompleteQuest;
};
