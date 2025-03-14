#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Poolable.h"
#include "BaseFood.generated.h"

UCLASS()
class PAPACHURROS_API ABaseFood : public AActor, public IPoolable
{
	GENERATED_BODY()
	
public:	
	ABaseFood();

	virtual void Tick(float DeltaTime) override;

	virtual void OnSpawnFromPool_Implementation() override;
	virtual void OnReturnToPool_Implementation() override;
	
protected:
	virtual void BeginPlay() override;


};
