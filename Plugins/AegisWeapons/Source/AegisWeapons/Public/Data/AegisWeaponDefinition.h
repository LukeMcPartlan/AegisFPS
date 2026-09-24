// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AegisWeaponSlot.h"
#include "AegisWeaponDefinition.generated.h"

class AAegisProjectile;

/**
 * One equippable weapon. Fire behavior (rate, spread, projectile) is data;
 * the weapon actor (phase 1) reads this and spawns AAegisProjectile.
 */
UCLASS(BlueprintType)
class AEGISWEAPONS_API UAegisWeaponDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	EWeaponSlot Slot = EWeaponSlot::Main;

	/** Projectile this weapon fires. Never hitscan. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	TSubclassOf<AAegisProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(ClampMin="0"))
	float Damage = 20.f;

	/** Seconds between shots. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(ClampMin="0.01"))
	float FireInterval = 0.15f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(ClampMin="0"))
	float SpreadDegrees = 1.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(ClampMin="1"))
	int32 MagazineSize = 30;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon")
	bool bAutomatic = true;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AegisWeapon", GetFName());
	}
};
