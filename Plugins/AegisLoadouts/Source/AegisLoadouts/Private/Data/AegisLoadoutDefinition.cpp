// Copyright RolyatWorks. All Rights Reserved.

#include "Data/AegisLoadoutDefinition.h"

bool UAegisLoadoutDefinition::IsValidLoadout() const
{
	if (!Character || !Ability1 || !Ability2 || !SecondaryWeapon)
	{
		return false;
	}

	const bool bHasMainOffhand = (MainWeapon != nullptr) && (OffhandWeapon != nullptr);
	const bool bHasTwoHanded = (TwoHandedWeapon != nullptr);

	// Exactly one primary configuration: not both, not neither.
	if (bHasMainOffhand == bHasTwoHanded)
	{
		return false;
	}

	return true;
}
