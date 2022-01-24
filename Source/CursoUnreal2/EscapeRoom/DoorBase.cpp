// Copyright Iker Noya 2022.


#include "DoorBase.h"

#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

ADoorBase::ADoorBase()
{
	PrimaryActorTick.bCanEverTick = true;
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Frame"));
	RootComponent = DoorFrame;
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimeline"));
}

void ADoorBase::UpdateTimeline(float Output)
{
	DoorOpeningLogic(Output);
}

void ADoorBase::BeginPlay()
{
	Super::BeginPlay();
	UpdateFunctionFloat.BindDynamic(this, &ADoorBase::UpdateTimeline);

	if (DoorTimelineFloatCurve)
	{
		DoorTimeline->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
	}
}

void ADoorBase::DoorOpeningLogic(float Value)
{
	FRotator NewRotation = {0.f, Value, 0.f};
	Door->SetRelativeRotation(NewRotation);
}

void ADoorBase::TryInteractWithDoor()
{
	if (!bIsDoorLocked)
	{
		if (DoorSound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), DoorSound, GetActorLocation());
		}
		if (!bIsDoorOpen)
		{
			DoorTimeline->Play();
			bIsDoorOpen=true;
		}
		else
		{
			DoorTimeline->Reverse();
			bIsDoorOpen=false;
		}
	}
}

void ADoorBase::Unlock()
{
	bIsDoorLocked = false;
}
