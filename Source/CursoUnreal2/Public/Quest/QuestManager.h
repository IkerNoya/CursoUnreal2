// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "GameFramework/Actor.h"
#include "QuestManager.generated.h"


UCLASS()
class CURSOUNREAL2_API AQuestManager : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TArray<AQuest*> Quests;
	
public:

	
	AQuestManager();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category = Quest)
	AQuest* GetQuestByName(FName Name);
	UFUNCTION()
	void CheckQuestStatus(FName QuestName);
	UFUNCTION(BlueprintCallable, Category = Quest)
	void AddQuest(AQuest* NewQuest);
	UFUNCTION(BlueprintCallable, Category = Quest)
	void RemoveQuest(AQuest* Quest);
	UFUNCTION(BlueprintCallable, Category = Quest)
	TArray<AQuest*>& GetQuests();
};
