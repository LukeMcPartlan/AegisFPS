// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AegisCharacter.generated.h"

class UAbilitySystemComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * Base playable character. Movement + camera + GAS hooks live here;
 * appearance comes from UAegisCharacterDefinition (AegisCharacters plugin),
 * weapons from AegisWeapons, abilities from AegisAbilities.
 */
UCLASS(Config=Game)
class AEGISFPS_API AAegisCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAegisCharacter();

	// IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystem; }

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// --- Gameplay Ability System ---
	/** Replicated ability system. Abilities are granted from the active loadout (phase 2). */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Aegis|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystem;

	// --- Enhanced Input ---
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aegis|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aegis|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aegis|Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aegis|Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aegis|Input")
	TObjectPtr<UInputAction> FireAction;

	/** E key. Bound to loadout ability slot 1 (phase 2). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aegis|Input")
	TObjectPtr<UInputAction> Ability1Action;

	/** Shift key. Bound to loadout ability slot 2 (phase 2). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aegis|Input")
	TObjectPtr<UInputAction> Ability2Action;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
