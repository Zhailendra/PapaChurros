#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BaseGameInstance.generated.h"

class UBaseOrder;

UCLASS()
class PAPACHURROS_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void AddOrder();

	UFUNCTION(BlueprintCallable)
	void RemoveOrder(UBaseOrder* Order);

	UFUNCTION(BlueprintCallable)
	TArray<UBaseOrder*> GetOrders() const { return Orders; }
	
protected:

private:

	TArray<UBaseOrder*> Orders;
	
};
