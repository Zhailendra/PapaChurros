// Fill out your copyright notice in the Description page of Project Settings.


#include "Tools/Fryer.h"

AFryer::AFryer()
{
	ToolName = "Fryer";
	MaxCapacity = 5;
	ChurrosCount = 0;
	CookingTime = 5.0f;
	bIsCooking = false;
}

void AFryer::BeginPlay()
{
	Super::BeginPlay();
}

void AFryer::AddChurros(int Amount)
{
	ChurrosCount = FMath::Clamp(ChurrosCount + Amount, 0, (int)MaxCapacity);
}

void AFryer::StartUse_Implementation()
{
	Super::StartUse();
	bIsCooking = true;
}

void AFryer::StopUse_Implementation()
{
	Super::StopUse();
	bIsCooking = false;
}
