// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "GameFramework/Actor.h"
#include "UI/MainHUD.h"
#include "QuestManager.generated.h"


class UQuestDataAsset;
UCLASS()
class CURSOUNREAL2_API AQuestManager : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HUD)
	AMainHUD* Hud;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TMap<int32, AQuest*> Quests;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	TArray<AQuest*> ActiveQuests;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	UDataTable* Data;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Data)
	TArray<FName> RowNames;
	UPROPERTY(BlueprintReadOnly, Category = Quest)
	int32 MaxActiveQuest = 3;
 
	AQuestManager();
private:
	void ActivateQuest(AQuest* Quest);
protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = Quest)
	AQuest* GetQuestByName(FName Name);
	UFUNCTION(BlueprintCallable, Category = Quest)
	AQuest* GetQuestById(int32 QuestId);
	UFUNCTION()
	void OnQuestCompleted(AQuest* Quest);

public:
	UFUNCTION(BlueprintCallable, Category = Quest)
	void AddQuest(AQuest* NewQuest);
	UFUNCTION(BlueprintCallable, Category = Quest)
	void RemoveQuest(int32 Id);
	void CheckQuestStatus(FQuestCheckList CheckList);
};
