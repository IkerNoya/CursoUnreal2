// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "GameFramework/Actor.h"
#include "UI/MainHUD.h"
#include "Data/QuestDataAsset.h"
#include "QuestManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestActivated, AQuest*, NewQuest);
UCLASS()
class CURSOUNREAL2_API AQuestManager : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TArray<AQuest*> Quests;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HUD)
	AMainHUD* Hud;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	UQuestDataAsset* QuestData;
	
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
	UPROPERTY(BlueprintAssignable)
	FOnQuestActivated OnQuestActivated;

};
