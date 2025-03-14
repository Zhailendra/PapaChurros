// Fill out your copyright notice in the Description page of Project Settings.


#include "Tools/BaseTools.h"

ABaseTools::ABaseTools()
{
	PrimaryActorTick.bCanEverTick = true;

	ToolMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ToolMesh"));
	RootComponent = ToolMesh;

	ToolName = "DefaultTool";
	MaxCapacity = 1.0f;
	bIsInUse = false;
}

void ABaseTools::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseTools::StartUse()
{
	bIsInUse = true;
}

void ABaseTools::StopUse()
{
	bIsInUse = false;
}
