// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/GameModeBase.h"
#include "UI/MainHUD.h"

#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Levels)
	FString CurrentLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Levels)
	FString NextLevelName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	AMainHUD* Hud;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	ATriggerBox* RespawnPoint;
	UPROPERTY()
	AActor* PlayerStart;

	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable, Category = Game)
	void NextLevel();
	UFUNCTION(BlueprintCallable, Category = Game)
	void RestartGame();
	UFUNCTION(BlueprintCallable, Category = Game)
	void QuitGame();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ActivateWinCondition();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ActivatePause();
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void RespawnPlayer(class AMainPlayer* Player);
};
