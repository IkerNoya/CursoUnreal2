// Copyright Iker Noya 2022.


#include "Core/MainGameMode.h"

#include "Core/MainGameInstance.h"
#include "CursoUnreal2/MainPlayer.h"
#include "Kismet/GameplayStatics.h"

void AMainGameMode::BeginPlay()
{
	
	Super::BeginPlay();
	CurrentLevel = UGameplayStatics::GetCurrentLevelName(GetWorld());
	UMainGameInstance* GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	AMainPlayer* Player = Cast<AMainPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	Hud = Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	if(GameInstance)
	{
		int32 Index = GameInstance->LevelNames.Find(CurrentLevel);
		if(Index < GameInstance->LevelNames.Num()-1)
		{
			NextLevelName = GameInstance->LevelNames[Index+1];
		}
		else
		{
			NextLevelName = GameInstance->LevelNames[0];
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("NO HAY GAMEINSTANCE PAPI"));
	}
	if(Player)
	{
		Player->Pause.AddDynamic(this, &AMainGameMode::ActivatePause);
		Player->Respawn.AddDynamic(this, &AMainGameMode::RespawnPlayer);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't get player character class"));
	}
	if(!Hud)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't cast hud"));
	}

	PlayerStart = FindPlayerStart(GetWorld()->GetFirstPlayerController());
	if(!PlayerStart)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't find player start"));
	}
	
}

void AMainGameMode::NextLevel()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	FInputModeGameOnly InputMode;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(InputMode);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor=false;
	UGameplayStatics::OpenLevel(GetWorld(), *NextLevelName);
}

void AMainGameMode::RestartGame()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	FInputModeGameOnly InputMode;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(InputMode);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor=false;
	UGameplayStatics::OpenLevel(GetWorld(), *CurrentLevel);
}

void AMainGameMode::QuitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
}

void AMainGameMode::RespawnPlayer(AMainPlayer* Player)
{
	if(RespawnPoint)
	{
		Player->SetActorLocation(RespawnPoint->GetActorLocation());
	}
	else
	{
		if(PlayerStart)
		{
			Player->SetActorLocation(PlayerStart->GetActorLocation());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("No player start"));
		}
	}
}
