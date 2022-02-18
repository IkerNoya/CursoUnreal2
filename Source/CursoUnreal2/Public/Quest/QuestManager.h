// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "GameFramework/Actor.h"
#include "UI/MainHUD.h"
#include "QuestManager.generated.h"

//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS
//TODO: KISS

class UQuestDataAsset;
UCLASS()
class CURSOUNREAL2_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY()
	TArray<FName> RowNames;
	UPROPERTY()
	int32 CurrentActiveQuests = 0;
	UPROPERTY()
	TArray<int32> QuestIds;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HUD)
	AMainHUD* Hud;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	TMap<int32, FQuestData> QuestStructMap;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	TArray<int32> ActiveQuestKeys;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	UDataTable* Data;

	UPROPERTY(BlueprintReadOnly, Category = Quest)
	int32 MaxActiveQuest = 3;
 
	AQuestManager();
	
protected:
	virtual void BeginPlay() override;
	
	int32 GetQuestIdFromName(FName Name);

public:

	void AddQuest(FQuestData NewQuest);
	
	void ActivateQuest(int32 QuestId);

	FQuestData& GetQuestFromId(int32 Id);
	FQuestData& GetQuestDataByName(FName Name);
	
	void CheckQuestStatus(FQuestCheckList CheckList);
};
