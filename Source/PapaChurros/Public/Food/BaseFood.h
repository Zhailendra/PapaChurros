#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Poolable.h"
#include "PoolSubsystem.h"
#include "BaseFood.generated.h"

class UBoxComponent;

UENUM(BlueprintType)
enum class EFoodType : uint8
{
	Churros UMETA(DisplayName = "Churros"),
	Croustillions UMETA(DisplayName = "Croustillions")
};

UCLASS()
class PAPACHURROS_API ABaseFood : public AActor, public IPoolable
{
	GENERATED_BODY()
    
public:    
	ABaseFood();

	virtual void Tick(float DeltaTime) override;

	virtual void OnSpawnFromPool_Implementation() override;
	virtual void OnReturnToPool_Implementation() override;

	void SetFoodType(EFoodType FoodType_) { FoodType = FoodType_; }

	UFUNCTION(BlueprintCallable)
	EFoodType GetFoodType() const { return FoodType; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	UPoolSubsystem* PoolSubsystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food Properties")
	EFoodType FoodType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	USceneComponent* RootComponentFood;
    
private:
};
