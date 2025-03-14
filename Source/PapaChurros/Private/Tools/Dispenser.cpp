// Fill out your copyright notice in the Description page of Project Settings.


#include "Tools/Dispenser.h"

ADispenser::ADispenser()
{
	ToolName = "Dispenser";
	MaxCapacity = 100.0f; // Exemple : 100 unités de liquide
	PouringSpeed = 10.0f;
	CurrentLiquidLevel = 0.0f;
	MaxLiquidLevel = 80.0f; // Dépassement au-delà de cette valeur
	bIsPouring = false;
	SelectedDrink = EDrinkType::Eau;
}

void ADispenser::BeginPlay()
{
	Super::BeginPlay();
}

void ADispenser::SelectDrink(EDrinkType NewDrink)
{
	SelectedDrink = NewDrink;
}

void ADispenser::StartUse_Implementation()
{
	Super::StartUse();
	bIsPouring = true;
}

void ADispenser::StopUse_Implementation()
{
	Super::StopUse();
	bIsPouring = false;
}
