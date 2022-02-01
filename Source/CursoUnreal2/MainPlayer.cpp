// Copyright Iker Noya 2022.


#include "MainPlayer.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Items/Item.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Camera);
	
	Grabber = CreateDefaultSubobject<UGrabberComponent>(TEXT("Grabber"));
	InteractComponent = CreateDefaultSubobject<UInteractComponent>(TEXT("Interact"));
	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	Inventory->Capacity = 20;

	TargetLocation = CreateDefaultSubobject<USceneComponent>(TEXT("TargetLocation"));
	TargetLocation->SetupAttachment(SpringArm);

	NormalSpeed = GetCharacterMovement()->MaxWalkSpeed;
}

void AMainPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if(TargetLocation)
	{
		OriginalTargetRotation = TargetLocation->GetComponentRotation();
	}
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bIsRotatingObject)
	{
		TargetLocation->AddRelativeRotation(ObjectRotation);
	}
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("Forward", this, &AMainPlayer::MoveForward);
		PlayerInputComponent->BindAxis("Right", this, &AMainPlayer::MoveRight);
		PlayerInputComponent->BindAxis("Turn", this, &AMainPlayer::Turn);
		PlayerInputComponent->BindAxis("LookUp", this, &AMainPlayer::LookUp);

		PlayerInputComponent->BindAction("Grab", IE_Pressed, this, &AMainPlayer::Grab);
		PlayerInputComponent->BindAction("Grab", IE_Released, this, &AMainPlayer::Drop);

		PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMainPlayer::HandleCrouch);
		PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMainPlayer::Interact);
		PlayerInputComponent->BindAction("ShowInventory", IE_Pressed, this, &AMainPlayer::HandleInventory);

		PlayerInputComponent->BindAction("ActivateRotation", IE_Pressed, this, &AMainPlayer::RotateObject);
		PlayerInputComponent->BindAction("ActivateRotation", IE_Released, this, &AMainPlayer::StopRotatingObject);

		PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMainPlayer::HandleSprint);
		PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMainPlayer::HandleSprint);
	}
}

void AMainPlayer::MoveForward(float Value)
{
	if (Value)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AMainPlayer::MoveRight(float Value)
{
	if (Value)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AMainPlayer::Turn(float Value)
{
	if (Value)
	{
		if (!bIsRotatingObject)
		{
			AddControllerYawInput(Value);
		}
		else
		{
			if (InputComponent && Grabber)
			{
				ObjectRotation.Yaw = Value*-1;
			}
		}
	}
	else
	{
		ObjectRotation.Yaw = 0;
	}
}

void AMainPlayer::LookUp(float Value)
{
	if (Value)
	{
		if (!bIsRotatingObject)
		{
			AddControllerPitchInput(Value);
		}
		else
		{
			if (TargetLocation)
			{
				ObjectRotation.Pitch = Value;
			}
		}
	}
	else
	{
		ObjectRotation.Pitch = 0;
	}
}

void AMainPlayer::HandleCrouch()
{
	if (bIsCrouched)
	{
		UnCrouch();
	}
	else
	{
		Crouch();
	}
}

void AMainPlayer::HandleSprint()
{
	bIsSprinting = !bIsSprinting;
	if(bIsSprinting)
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
	}
}


void AMainPlayer::Grab()
{
	if (Grabber)
	{
		Grabber->Grab();
	}
}

void AMainPlayer::Drop()
{
	if (Grabber)
	{
		Grabber->Drop();
		StopRotatingObject();
		TargetLocation->SetWorldRotation(OriginalTargetRotation);
	}
}

void AMainPlayer::Interact()
{
	if (InteractComponent)
	{
		InteractComponent->Interact();
		if (Inventory->ItemEquipped)
		{
			Inventory->ItemEquipped = nullptr;
		}
	}
}

void AMainPlayer::UseItem(UItem* Item)
{
	if (Item)
	{
		Item->Use(this);
		Item->OnUse(this);
	}
}

void AMainPlayer::RotateObject()
{
	if (Grabber)
	{
		if (Grabber->bIsObjectGrabbed)
		{
			bIsRotatingObject = true;
		}
	}
}

void AMainPlayer::StopRotatingObject()
{
	bIsRotatingObject = false;
}
