// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Player/MainPlayer.h"
#include "UObject/Object.h"
#include "Quest/QuestCheckList.h"
#include "TaskBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSendData, FQuestCheckList, List);

UCLASS(DefaultToInstanced,EditInlineNew,BlueprintType, Blueprintable)
class CURSOUNREAL2_API UTaskBase : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Task)
	class UUserQuestComponent* QuestComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Task)
	AMainPlayer* Player;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Task)
	FQuestCheckList CheckList;
	
	virtual void SetDelegates(){}
	virtual void InitializeVariables();

	virtual void BeginDestroy() override;
	
public:
	void InitializeTask(UUserQuestComponent* Component);
	FSendData SendData;

};
