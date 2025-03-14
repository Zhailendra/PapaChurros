#include "Common/BaseGameInstance.h"

#include "Order/BaseOrder.h"

void UBaseGameInstance::AddOrder(UBaseOrder* Order)
{
	Orders.Add(Order);
}

void UBaseGameInstance::RemoveOrder(UBaseOrder* Order)
{
	Orders.Remove(Order);
}
