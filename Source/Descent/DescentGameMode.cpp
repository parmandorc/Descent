// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Descent.h"
#include "DescentGameMode.h"
#include "DescentHUD.h"
#include "DescentCharacter.h"

ADescentGameMode::ADescentGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADescentHUD::StaticClass();
}
