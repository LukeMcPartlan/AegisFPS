// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AegisPlayerState.generated.h"

class UAegisLoadoutDefinition;

/**
 * Replicated per-player data: team assignment + chosen loadout.
 * Loadout content itself lives in the AegisLoadouts plugin as data assets.
 */
UCLASS()
class AEGISFPS_API AAegisPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AAegisPlayerState();

	/** 0 or 1 for 2v2. Assigned by the game mode on login (phase 4). */
	UPROPERTY(Replicated, BlueprintReadOnly, Category="Aegis|Teams")
	int32 TeamId = 0;

	/** The loadout this player picked in the menu (phase 3). */
	UPROPERTY(Replicated, BlueprintReadOnly, Category="Aegis|Loadout")
	TObjectPtr<UAegisLoadoutDefinition> ActiveLoadout = nullptr;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
