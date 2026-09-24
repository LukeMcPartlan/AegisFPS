// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AegisAbilitySlot.generated.h"

/** Loadout ability slots. Slot 1 = E, Slot 2 = Shift. */
UENUM(BlueprintType)
enum class EAegisAbilitySlot : uint8
{
	Ability1_E     UMETA(DisplayName="Ability 1 (E)"),
	Ability2_Shift UMETA(DisplayName="Ability 2 (Shift)"),
};
