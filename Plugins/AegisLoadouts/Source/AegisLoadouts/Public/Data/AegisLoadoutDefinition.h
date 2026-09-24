// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AegisLoadoutDefinition.generated.h"

class UAegisCharacterDefinition;
class UAegisAbilityDefinition;
class UAegisWeaponDefinition;

/**
 * CoD-style loadout: 1 character + 2 abilities (E / Shift) + weapons.
 * Weapon rule: (Main + Offhand) XOR TwoHanded, plus a Secondary always.
 */
UCLASS(BlueprintType)
class AEGISLOADOUTS_API UAegisLoadoutDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loadout")
	TObjectPtr<UAegisCharacterDefinition> Character;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loadout")
	TObjectPtr<UAegisAbilityDefinition> Ability1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loadout")
	TObjectPtr<UAegisAbilityDefinition> Ability2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loadout|Primary")
	TObjectPtr<UAegisWeaponDefinition> MainWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loadout|Primary")
	TObjectPtr<UAegisWeaponDefinition> OffhandWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loadout|Primary")
	TObjectPtr<UAegisWeaponDefinition> TwoHandedWeapon;

	/** Single-wielded, held with both hands. Always equipped. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loadout|Secondary")
	TObjectPtr<UAegisWeaponDefinition> SecondaryWeapon;

	/** Enforces the weapon-combo rule so bad loadouts can't ship. */
	UFUNCTION(BlueprintCallable, Category="Loadout")
	bool IsValidLoadout() const;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AegisLoadout", GetFName());
	}
};
