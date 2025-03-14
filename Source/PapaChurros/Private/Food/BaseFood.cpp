#include "Food/BaseFood.h"

ABaseFood::ABaseFood()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseFood::BeginPlay()
{
	Super::BeginPlay();
	
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

