// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FQuestStruct.h"
#include "Quest.generated.h"

UCLASS()
class CURSOUNREAL2_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FQuestStruct QuestData;

	AQuest();

protected:
	virtual void BeginPlay() override;
	

};
