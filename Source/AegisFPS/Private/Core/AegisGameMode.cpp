// Copyright RolyatWorks. All Rights Reserved.

#include "Core/AegisGameMode.h"
#include "Core/AegisCharacter.h"
#include "Core/AegisPlayerController.h"
#include "Core/AegisGameState.h"
#include "Core/AegisPlayerState.h"

AAegisGameMode::AAegisGameMode()
{
	DefaultPawnClass = AAegisCharacter::StaticClass();
	PlayerControllerClass = AAegisPlayerController::StaticClass();
	GameStateClass = AAegisGameState::StaticClass();
	PlayerStateClass = AAegisPlayerState::StaticClass();
}
