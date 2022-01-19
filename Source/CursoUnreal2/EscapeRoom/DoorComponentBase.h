// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSOUNREAL2_API UDoorComponentBase : public UActorComponent
{
	GENERATED_BODY()


	bool bOpenDoorSound = false;
	bool bCloseDoorSound = true;
	bool bShouldOpenDoor = false;

	float InitialYaw = 0.f;
	float CurrentYaw=0.f;
	float TargetOpenedDoorYaw = 0.f;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DoorSettings)
	float OpeningSpeed = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DoorSettings)
	float OpenedAngle = 90.f;
	
	UPROPERTY(EditAnywhere, category = Audio)
	UAudioComponent* DoorSound;

public:	
	// Sets default values for this component's properties
	UDoorComponentBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void FindAudioComponent();
	
	virtual void OpenDoor();
	virtual void CloseDoor();

		
};
