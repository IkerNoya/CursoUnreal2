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
	
	UPROPERTY()
	TArray<FName> RowNames;
	UPROPERTY()
	int32 CurrentActiveQuests = 0;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HUD)
	AMainHUD* Hud;

public:
	//ACTOR------------------------------------------------------	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TMap<int32, AQuest*> Quests;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	TArray<AQuest*> ActiveQuests;

	//DATA TABLE--------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	TMap<int32, FQuestData> QuestStructMap;
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	// TArray<FQuestData> ActiveQuestData;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	UDataTable* Data;

	UPROPERTY(BlueprintReadOnly, Category = Quest)
	int32 MaxActiveQuest = 3;
 
	AQuestManager();
private:
	bool CheckIfStructExist(TArray<FQuestData>& Array, FQuestData& ToCheck, int32& Index);
	void UpdateMainQuestMap(int32 Id, FQuestData NewData);
	
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

	void AddQuest(FQuestData NewQuest);
	
	UFUNCTION(BlueprintCallable, Category = Quest)
	void ActivateQuest(AQuest* Quest);
	
	void ActivateQuest(FQuestData& Quest);
	
	UFUNCTION(BlueprintCallable, Category = Quest)
	void RemoveQuest(int32 Id);
	void CheckQuestStatus(FQuestCheckList CheckList);
};
