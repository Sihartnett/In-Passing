// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Unbelievable_SaveGame.generated.h"


/**
 * 
 */
UCLASS()
class UNBELIEVABLE_API UUnbelievable_SaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UUnbelievable_SaveGame();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector PlayerLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator PlayerRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float gameTimeTotal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 FString dateOfLastPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString modeOfPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int numberOfDeathes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int levelPlayed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool WingedToggleSave = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool NarrativeToggleSave = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SensitivitySave = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MasterVolumeSave = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SFXVolumeSave = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MusicVolumeSave = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextureRenderTarget2D* ScreenshotSave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool WingedWasUsed = false;
};
