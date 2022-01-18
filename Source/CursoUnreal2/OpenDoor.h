// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSOUNREAL2_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()
	float TargetYaw = 0.f;
	float InitialYaw = 0.f;
	float CurrentYaw=0.f;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Speed)
	float OpenedAngle = 90.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Speed)
	float DegreesPerSecond = 45;
	UPROPERTY(EditAnywhere, category = Door)
	ATriggerVolume* PreassurePlate;
	UPROPERTY(EditAnywhere, Category = Instigator)
	AActor* ActorThatOpen;
public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor(float DeltaTime);
		
};
