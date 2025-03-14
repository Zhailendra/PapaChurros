#pragma once

#include "CoreMinimal.h"
#include "Poolable.h"
#include "GameFramework/Actor.h"
#include "NpcActor.generated.h"

class ABaseFood;
class UCapsuleComponent;
class UBaseOrder;
class UPoolSubsystem;

UCLASS()
class PAPACHURROS_API ANpcActor : public AActor, public IPoolable
{
	GENERATED_BODY()
	
public:	
	ANpcActor();
	
	virtual void Tick(float DeltaTime) override;

	virtual void OnSpawnFromPool_Implementation() override;
	virtual void OnReturnToPool_Implementation() override;

	void InitOrder();

protected:
	virtual void BeginPlay() override;

	void SetOrder(UBaseOrder* NewOrder) { Order = NewOrder; }

	UFUNCTION(BlueprintCallable)
	UBaseOrder* GetOrder() const { return Order; }

	UPROPERTY(EditAnywhere, Category = "Food Class")
	TSubclassOf<ABaseFood> FoodClass;

	UPROPERTY()
	UPoolSubsystem* PoolSubsystem;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Order", meta = (AllowPrivateAccess = "true"))
	UBaseOrder* Order;

};
