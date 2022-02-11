// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "QuestManager.h"
#include "Components/ActorComponent.h"
#include "Quest/Tasks/TaskBase.h"
#include "UserQuestComponent.generated.h"
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSOUNREAL2_API UUserQuestComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Quest)
	AQuestManager* QuestManager;

public:
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadOnly, Category = Task)
	TArray<UTaskBase*> Tasks;


	UUserQuestComponent();


protected:

	virtual void BeginPlay() override;
	UFUNCTION()
	void SendData(FQuestCheckList List);

	

		
};
