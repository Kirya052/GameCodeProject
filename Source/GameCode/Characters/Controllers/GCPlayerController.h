// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GCPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMECODE_API AGCPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;

	bool GetIgnoreCameraPitch() const;

	void SetIgnoreCameraPitch(bool bIgnoreCameraPitch_In);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<class UPlayerHUDWidget> PlayerHudWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<class UUserWidget> MainMenuWidgetClass;

	virtual void SetupInputComponent() override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void TurnAtRate(float Value);
	void LookUpAtRate(float Value);
	void ChangeCrouchState();
	void Mantle();
	void Jump();

	void SwimForward(float Value);
	void SwimRight(float Value);
	void SwimUp(float Value);

	void ClimbLadderUp(float Value);
	void InteractWithLadder();

	void StartSprint();
	void StopSprint();

	void PlayerStartFire();
	void PlayerStopFire();

	void StartAiming();
	void StopAiming();
	
	void NextItem();
	void PreviousItem();

	void EquipPrimaryItem();
	void Reload();

	void PrimaryMeleeAttack();
	void SecondaryMeleeAttack();

	void ToggleMainMenu();

	void Interact();
	void UseInventory();

	void QuickSaveGame();
	void QuickLoadGame();

#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
	void Debug_IncreaseGlobalDilation();
	void Debug_DecreaseGlobalDilation();
#endif

	TSoftObjectPtr<class AGCBaseCharacter> CachedBaseCharacter;
	
private:
	void OnInteractableObjectFound(FName ActionName);
	void CreateAndInitializeWidgets();

	UPlayerHUDWidget* PlayerHUDWidget = nullptr;
	UUserWidget* MainMenuWidget = nullptr;

	bool bIgnoreCameraPitch = false;
};
