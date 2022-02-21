// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "../EscapeRoom/DoorBase.h"
#include "Player/MainPlayer.h"
#include "KeyDoor.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API AKeyDoor : public ADoorBase, public IInteractionInterface
{
	GENERATED_BODY()

	UPROPERTY()
	AMainPlayer* Player;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Key)
	class UItem* KeyToOpen = nullptr;

protected:
	virtual void BeginPlay() override;
	
public:
	AKeyDoor();

	virtual void HandleInteraction() override;
};
