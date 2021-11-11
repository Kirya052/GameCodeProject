// Fill out your copyright notice in the Description page of Project Settings.


#include "Adrenaline.h"

bool UAdrenaline::Consume(AGCBaseCharacter* ConsumeTarget)
{
	ConsumeTarget->RestoreFullStamina();
	this->ConditionalBeginDestroy();
	return true;
}
