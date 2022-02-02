 // Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GrabberComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CURSOUNREAL2_API UGrabberComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = Grab)
	float Reach = 50.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	FVector PlayerLocation;
	FRotator PlayerRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grabber)
	float ThrowForce = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grabber)
	USceneComponent* TargetLocation;

	


public:
	bool bIsObjectGrabbed = false;
	
	UGrabberComponent();

protected:
	virtual void BeginPlay() override;

private:
	void FindPhysicsHandle();
	FHitResult GetFirstPhysicsBodyInReach();
	FVector GetPlayerReach() const;
	void SetPlayerLocationAndRotation(); 
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category=Grabber)
	void Grab();
	UFUNCTION(BlueprintCallable, Category=Grabber)
	void Drop();
	UFUNCTION(BlueprintCallable, Category=Grabber)
	void RotateObject(FRotator Value);
	UFUNCTION(BlueprintCallable, Category=Grabber)
	void Throw(FVector Direction);
};
