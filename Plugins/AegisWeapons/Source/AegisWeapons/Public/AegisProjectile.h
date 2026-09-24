// Copyright RolyatWorks. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AegisProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

/**
 * Base for ALL weapon fire. No hitscan anywhere: every weapon spawns one of
 * these (or a subclass). Server-authoritative; movement replicates.
 * Phase 2 routes damage through GAS GameplayEffects; phase 0 uses ApplyDamage.
 */
UCLASS()
class AEGISWEAPONS_API AAegisProjectile : public AActor
{
	GENERATED_BODY()

public:
	AAegisProjectile();

	/** Call on the server to launch. Direction should be normalized. */
	UFUNCTION(BlueprintCallable, Category="Aegis|Projectile")
	void FireInDirection(const FVector& Direction);

protected:
	UPROPERTY(VisibleDefaultsOnly, Category="Projectile")
	TObjectPtr<USphereComponent> CollisionComp;

	UPROPERTY(VisibleDefaultsOnly, Category="Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile", meta=(ClampMin="0"))
	float Damage = 20.f;

	/** Seconds before the projectile cleans itself up. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile", meta=(ClampMin="0.1"))
	float LifeSeconds = 5.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
