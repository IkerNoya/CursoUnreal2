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
	bool bShouldOpenDoor = false;

	// Sets default values for this component's properties
	UDoorComponentBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void FindAudioComponent();
	
	virtual void OpenDoor(float DeltaTime);
	virtual void CloseDoor(float DeltaTime);

	virtual void OpenDoorLogic(float DeltaTime);
	virtual void CloseDoorLogic(float DeltaTime);

	
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void ActivateDoor(bool bShouldActivate);

		
};
