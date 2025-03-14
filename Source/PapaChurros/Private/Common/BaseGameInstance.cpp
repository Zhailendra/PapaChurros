#include "Common/BaseGameInstance.h"

#include "Order/BaseOrder.h"

void UBaseGameInstance::AddOrder()
{
	UBaseOrder *NewOrder = NewObject<UBaseOrder>(this);

	NewOrder->SetNbAliment(5);
	NewOrder->SetHasDrink(false);

	for (int i = 0; i < 5; i++)
	{
		ABaseFood *NewFood = NewObject<ABaseFood>(this);
		NewFood->SetFoodType(EFoodType::Churros);
		ABaseFood *NewFood2 = NewObject<ABaseFood>(this);
		NewFood->SetFoodType(EFoodType::Croustillions);
		NewOrder->AddAliment(NewFood);
		NewOrder->AddAliment(NewFood2);
	}

	Orders.Add(NewOrder);
}

void UBaseGameInstance::RemoveOrder(UBaseOrder* Order)
{
	Orders.Remove(Order);
}
