// Fill out your copyright notice in the Description page of Project Settings.

#include "Unbelievable_SaveGame.h"
#include "Unbelievable.h"

UUnbelievable_SaveGame::UUnbelievable_SaveGame()
{
	PlayerLocation = FVector(0.f, 0.f, 0.f);
	PlayerRotation = FRotator(0.f, 0.f, 0.f);
	gameTimeTotal = 12.0f;
	dateOfLastPlay = FString(TEXT("9/07/2019"));
	modeOfPlay = FString(TEXT("Exploration"));
	numberOfDeathes = 7;
	levelPlayed = 1;
	WingedToggleSave = false;
	NarrativeToggleSave = true;
	SensitivitySave = 45.0f;
	MasterVolumeSave = 1.0f;
	SFXVolumeSave = 1.0f;
	MusicVolumeSave = 1.0f;
	ScreenshotSave;
	WingedWasUsed = false;
}
