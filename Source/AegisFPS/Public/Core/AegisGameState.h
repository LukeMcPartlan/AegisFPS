// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AegisGameState.generated.h"

/**
 * Replicated match state: team scores live here so every client's HUD stays in sync.
 */
UCLASS()
class AEGISFPS_API AAegisGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	/** Score per team index (0 and 1 for 2v2). */
	UPROPERTY(Replicated, BlueprintReadOnly, Category="Aegis|Teams")
	TArray<int32> TeamScores;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
