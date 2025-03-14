#include "Order/BaseOrder.h"

UBaseOrder::UBaseOrder()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UBaseOrder::BeginPlay()
{
	Super::BeginPlay();

	
}


void UBaseOrder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

