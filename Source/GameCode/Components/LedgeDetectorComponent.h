// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LedgeDetectorComponent.generated.h"

/** Description of a detected ledge.
 * 
 * Used for implementing mantling mechanics. Returned as an output parameter by LedgeDetectorComponent's method DetectLedge
 * @see ULedgeDetectorComponent, GCBaseCharacter::Mantle 
 */
USTRUCT(BlueprintType)
struct FLedgeDescription
{
	GENERATED_BODY()

	/** Player's location for detected ledge (considering a player's capsule half-height) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ledge description")
	FVector Location;

	/** Ledge 2D normal (without Z-coordinate). Returned by forward sweep test in a ULedgeDetectorComponent::DetectLedgeMethod */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ledge description")
	FVector LedgeNormal;

	/** Player's rotation on a detected ledge. Orientation of negative ledge normal */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ledge description")
	FRotator Rotation;
};

/** Component for detecting available ledges for a mantling movement.
* 
*	Detects a suitable ledge (collision channel ECC_Climbable) with DetectLedge method,
*   considering Minimal and Maximal ledge heights.  
*/
UCLASS()
class GAMECODE_API ULedgeDetectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	/**
	 * Detects a ledge available for mantling.
	 * 
	 * Uses 3 geometric queries:
	 * 1. Forward test (channel ECC_Climbable): capsule sweep from a player's position in a movement direction by ForwardCheckDistance value.
	 * Capsule radius equals to a player's capsule radius. Capsule height equals to MaximumLedgeHeight - MinimumLedgeHeight 
	 * 2. Downward test (channel ECC_Climbable): sphere sweep from a ledge maximum height (considering a current player bottom and sweep radius).
	 * Radius equals to a player's capsule radius.
	 * 3. Overlap test (Pawn profile): checks that player's capsule doesn't overlap with anything at a ledge's position.
	 *
	 * @param LedgeDescription - output parameter set to a valid value when a ledge is successfully detected 
	 * @return true when a ledge is detected, false otherwise
	*/
	bool DetectLedge(OUT FLedgeDescription& LedgeDescription);

protected:
	/** Override of UActorComponent::BeginPlay()
	 * @see UActorComponent::BeginPlay()
	 * Setting CachedCharacterOwner. Assertion when we try to use component with any other class than ACharcter */
	virtual void BeginPlay() override;

	/** Minimal height from Player's bottom to a detected ledge. Usually equals to MaxStepHeight from UCharacterMovememntComponent */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Detection settings", meta = (UIMin = 0.0f, ClampMin = 0.0f))
	float MinimumLedgeHeight = 40.0f;

	/** Maximal height from Player's bottom to a detected ledge. Determines maximal height of an obstacle available for mantling */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Detection settings", meta = (UIMin = 0.0f, ClampMin = 0.0f))
	float MaximumLedgeHeight = 200.0f;

	/** Maximum distance from player to a detected ledge in a movement direction. Determines maximum distance when a player starts mantling */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Detection settings", meta = (UIMin = 0.0f, ClampMin = 0.0f))
	float ForwardCheckDistance = 100.0f;

private:
	/** Pointer to a component's owner casted to ACharacter class */
	TWeakObjectPtr<class ACharacter> CachedCharacterOwner;
};
