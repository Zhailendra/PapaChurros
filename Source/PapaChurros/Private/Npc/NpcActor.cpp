#include "Npc/NpcActor.h"
#include "Components/CapsuleComponent.h"
#include "Order/BaseOrder.h"

ANpcActor::ANpcActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = SceneComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(SceneComponent);

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComponent->SetupAttachment(MeshComponent);
}

void ANpcActor::BeginPlay()
{
	Super::BeginPlay();

	PoolSubsystem = GetWorld()->GetSubsystem<UPoolSubsystem>();
}

void ANpcActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANpcActor::OnSpawnFromPool_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("OnSpawnFromPool_Implementation"));
}

void ANpcActor::OnReturnToPool_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("OnReturnToPool_Implementation"));
}

void ANpcActor::InitOrder()
{
	if (!Order)
	{
		Order = NewObject<UBaseOrder>(this);
	}

	int NbAliments = FMath::RandRange(minFood, maxFood);
	Order->SetNbAliment(NbAliments);

	bool bHasDrink = FMath::RandBool();
	Order->SetHasDrink(bHasDrink);

	TArray<EFoodType> FoodTypes = { EFoodType::Churros, EFoodType::Croustillions, EFoodType::Donut, EFoodType::Gauffre };

	Order->GetAliments().Empty();

	for (int i = 0; i < NbAliments; i++)
	{
		EFoodType RandomFoodType = FoodTypes[FMath::RandRange(0, FoodTypes.Num() - 1)];

		ABaseFood* NewFood = PoolSubsystem->SpawnFromPool<ABaseFood>(FoodClass, FVector::ZeroVector, FRotator::ZeroRotator, nullptr);
		if (NewFood)
		{
			NewFood->SetFoodType(RandomFoodType);
			Order->AddAliment(NewFood);
		}
	}

	TArray<EFoodType> DrinkTypes = { EFoodType::Cola, EFoodType::Lemon, EFoodType::OrangeBlast };

	if (bHasDrink) {
		EFoodType RandomDrinkType = DrinkTypes[FMath::RandRange(0, DrinkTypes.Num() - 1)];

		ABaseFood* NewDrink = PoolSubsystem->SpawnFromPool<ABaseFood>(FoodClass, FVector::ZeroVector, FRotator::ZeroRotator, nullptr);
		if (NewDrink)
		{
			NewDrink->SetFoodType(RandomDrinkType);
			Order->AddAliment(NewDrink);
		}
	}

	for (ABaseFood* Food : Order->GetAliments())
	{
		if (Food)
		{
			UE_LOG(LogTemp, Log, TEXT("Aliment: %s"), *UEnum::GetValueAsString(Food->GetFoodType()));
		}
	}
}


