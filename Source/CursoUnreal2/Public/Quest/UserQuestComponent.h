// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "QuestManager.h"
#include "Components/ActorComponent.h"
#include "UserQuestComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSOUNREAL2_API UUserQuestComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Quest)
	AQuestManager* QuestManager;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Quest)
	TArray<AQuest*> ActiveQuest;

public:	
	// Sets default values for this component's properties
	UUserQuestComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void AddActiveQuest(AQuest* NewQuest);
	

		
};
