// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "QuestManager.h"
#include "Components/ActorComponent.h"
#include "CursoUnreal2/QuestInterface.h"
#include "ObjectivePickup.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CURSOUNREAL2_API UObjectivePickup : public UActorComponent, public IQuestInterface
{
	GENERATED_BODY()
	
	UPROPERTY()
	AQuestManager* QuestManager;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	FName QuestName = NAME_None;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	int32 ObjectiveId=0;
	
	bool bItemAlreadyPickedUp = false;
	
public:
	UObjectivePickup();

protected:
	virtual void BeginPlay() override;
	
	virtual void OnPickup() override;

};
