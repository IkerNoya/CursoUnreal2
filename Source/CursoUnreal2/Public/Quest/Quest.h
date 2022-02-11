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

UCLASS()
class CURSOUNREAL2_API AQuest : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FName Name;
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompleteQuest, AQuest*, Quest);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	TArray<FObjectivesStruct> Objectives;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Quest)
	EQuestState QuestState;

	AQuest();

private:
	virtual void BeginDestroy() override;

protected:
	virtual void BeginPlay() override;

	void CompleteQuest();

public:
	UFUNCTION(BlueprintCallable, Category = Quest)
	FName GetQuestName();
	
	void CheckQuestStatus(FQuestCheckList CheckList);
	
	EQuestState GetQuestState();
	void SetQuestState(EQuestState State);
	
	UPROPERTY(BlueprintAssignable)
	FOnCompleteQuest OnCompleteQuest;
};


