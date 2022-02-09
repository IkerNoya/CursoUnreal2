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

public:	

	UUserQuestComponent();


protected:

	virtual void BeginPlay() override;
	
	

		
};
