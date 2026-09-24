// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AegisCharacterDefinition.generated.h"

class USkeletalMesh;

USTRUCT(BlueprintType)
struct FAegisAppearanceOption
{
	GENERATED_BODY()

	/** Stable id used by the creation menu, e.g. "skin_tone", "face_paint". */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName OptionId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText DisplayName;

	/** Values the player picks from, e.g. material or color variants. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FName> Values;
};

/**
 * Data-driven character. The WoW-style creation menu edits these;
 * adding a character = new asset, zero code.
 */
UCLASS(BlueprintType)
class AEGISCHARACTERS_API UAegisCharacterDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Identity")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Identity")
	FText Description;

	/** Base mesh; the creation menu swaps materials/attachments on it. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Appearance")
	TSoftObjectPtr<USkeletalMesh> BaseMesh;

	/** Customization axes shown in the creation menu. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Appearance")
	TArray<FAegisAppearanceOption> AppearanceOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Stats", meta=(ClampMin="1"))
	float BaseHealth = 200.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Stats", meta=(ClampMin="1"))
	float BaseMoveSpeed = 600.f;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AegisCharacter", GetFName());
	}
};
