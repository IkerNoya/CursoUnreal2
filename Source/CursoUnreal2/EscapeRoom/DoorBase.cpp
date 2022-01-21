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
	FRotator NewRotation = {0.f, Output, 0.f};
	Door->SetRelativeRotation(NewRotation);
}

void ADoorBase::BeginPlay()
{
	Super::BeginPlay();
	UpdateFunctionFloat.BindDynamic(this, &ADoorBase::UpdateTimeline);

	if(DoorTimelineFloatCurve)
	{
		DoorTimeline->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
	}
}

void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoorBase::TryInteractWithDoor()
{
	if (!bIsDoorLocked)
	{
		if(!bIsDoorOpen)
		{
			OpenDoor();
		}
		else
		{
			CloseDoor();
		}
	}
}

void ADoorBase::OpenDoor()
{
		if (DoorSound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), DoorSound, GetActorLocation());
		}
		DoorTimeline->Play();
		bIsDoorOpen=true;
}

void ADoorBase::CloseDoor()
{
		if (DoorSound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), DoorSound, GetActorLocation());
		}
		DoorTimeline->Reverse();
		bIsDoorOpen=false;
}

void ADoorBase::Unlock()
{
	bIsDoorLocked = false;
}
