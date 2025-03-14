#include "Food/BaseFood.h"

#include "Components/BoxComponent.h"

ABaseFood::ABaseFood()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponentFood = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootComponentFood);
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);

}

void ABaseFood::BeginPlay()
{
	Super::BeginPlay();

	PoolSubsystem = GetWorld()->GetSubsystem<UPoolSubsystem>();
}

void ABaseFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseFood::OnSpawnFromPool_Implementation()
{
	IPoolable::OnSpawnFromPool_Implementation();
}

void ABaseFood::OnReturnToPool_Implementation()
{
	IPoolable::OnReturnToPool_Implementation();
}

