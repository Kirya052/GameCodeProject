// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUDWidget.generated.h"

/**
 * 
 */
 class UHighlightInteractable;
UCLASS()
class GAMECODE_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	class UReticleWidget* GetReticleWidget();

	class UAmmoWidget* GetAmmoWidget();

	void SetHighlightInteractebleVisibility(bool bIsVisible);
	void SetHightInteractableActionText(FName KeyName);

protected:
	UFUNCTION(BlueprintCallable)
	float GetHealthPercent() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget names")
	FName ReticleWidgetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget names")
	FName AmmoWidgetName;

	UPROPERTY(meta = (BindWidget))
	UHighlightInteractable* InteractableKey;
};
