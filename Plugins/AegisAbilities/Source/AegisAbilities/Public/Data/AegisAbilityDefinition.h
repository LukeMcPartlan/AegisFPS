// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AegisAbilitySlot.h"
#include "AegisAbilityDefinition.generated.h"

class UGameplayAbility;

/**
 * One equippable ability. The loadout menu picks two of these;
 * the ability logic itself is a UGameplayAbility subclass (GAS, phase 2).
 */
UCLASS(BlueprintType)
class AEGISABILITIES_API UAegisAbilityDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability")
	TSubclassOf<UGameplayAbility> AbilityClass;

	/** Which key this occupies in the loadout. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability")
	EAegisAbilitySlot Slot = EAegisAbilitySlot::Ability1_E;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability", meta=(ClampMin="0"))
	float CooldownDuration = 8.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability")
	TSoftObjectPtr<UTexture2D> Icon;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AegisAbility", GetFName());
	}
};
