// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AegisGameMode.generated.h"

class AAegisCharacter;
class AAegisPlayerController;
class AAegisGameState;
class AAegisPlayerState;

/**
 * Team-based game mode. Starts as 2v2 on a listen server;
 * PlayersPerTeam scales to 6 for the dedicated-server milestone.
 */
UCLASS(Config=Game)
class AEGISFPS_API AAegisGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAegisGameMode();

	/** Players per team. 2 = 2v2 (current), 6 = 6v6 (dedicated milestone). */
	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly, Category="Aegis|Teams")
	int32 PlayersPerTeam = 2;
};
