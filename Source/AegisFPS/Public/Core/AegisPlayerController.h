// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AegisPlayerController.generated.h"

/**
 * Owns the client-side menu flow (character creation, loadout) in phase 3.
 * Server RPCs for loadout selection get added with the UI milestone.
 */
UCLASS()
class AEGISFPS_API AAegisPlayerController : public APlayerController
{
	GENERATED_BODY()
};
