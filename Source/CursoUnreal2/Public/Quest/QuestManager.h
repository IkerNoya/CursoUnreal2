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
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TArray<AQuest*> Quests;
	
	AQuestManager();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category = Quest)
	AQuest* GetQuestByName(FName Name);
	UFUNCTION()
	void CheckQuestStatus(FName QuestName);
};
