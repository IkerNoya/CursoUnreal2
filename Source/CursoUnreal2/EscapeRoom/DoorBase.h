// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "DoorBase.generated.h"

UCLASS()
//TODO: Tratar de crear cosas con la menor conexion entre si posibles
//Responsabilidad de puerta: Abrir y Cerrar
class CURSOUNREAL2_API ADoorBase : public AActor
{
	GENERATED_BODY()

	bool bIsDoorOpen=false;
	FOnTimelineFloat UpdateFunctionFloat;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Mesh)
	UStaticMeshComponent* DoorFrame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Mesh)
	UStaticMeshComponent* Door;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Settings)
	UTimelineComponent* DoorTimeline;
	UPROPERTY(EditAnywhere, Category=Settings)
	UCurveFloat* DoorTimelineFloatCurve;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	bool bIsDoorLocked=false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	USoundBase* DoorSound;

	
public:	
	ADoorBase();

private:
	
	UFUNCTION()
	void UpdateTimeline(float Output);
	
protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void TryInteractWithDoor();
	UFUNCTION(BlueprintCallable, Category=Action)
	void OpenDoor();
	UFUNCTION(BlueprintCallable, Category=Action)
	void CloseDoor();
	void Unlock();
};
