 // Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GrabberComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class CURSOUNREAL2_API UGrabberComponent : public UActorComponent
{
	GENERATED_BODY()

	FVector LineTraceEnd;
	FVector PlayerLocation;
	FRotator PlayerRotation;
	
protected:
	UPROPERTY(EditAnywhere, Category = Grab)
	float Reach = 50.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	
public:	
	// Sets default values for this component's properties
	UGrabberComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void FindPhysicsHandle();
	FHitResult GetFirstPhysicsBodyInReach();	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category=Grabber)
	void Grab();
	UFUNCTION(BlueprintCallable, Category=Grabber)
	void Drop();
};
