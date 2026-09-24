// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AegisWeaponSlot.generated.h"

/** Weapon equip slots. Primary = (Main + Offhand) XOR TwoHanded. */
UENUM(BlueprintType)
enum class EWeaponSlot : uint8
{
	Main       UMETA(DisplayName="Main Hand"),
	Offhand    UMETA(DisplayName="Off Hand"),
	TwoHanded  UMETA(DisplayName="Two-Handed"),
	/** Single-wielded weapon held with both hands. Always equipped. */
	Secondary  UMETA(DisplayName="Secondary"),
};
