#include "Npc/NpcSpawner.h"
#include "PoolSubsystem.h"
#include "Npc/NpcActor.h"
#include "EngineUtils.h"

ANpcSpawner::ANpcSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootSceneComponent;
	
	SpawnNpc1 = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnNpc1"));
	SpawnNpc1->SetupAttachment(RootComponent);

	SpawnNpc2 = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnNpc2"));
	SpawnNpc2->SetupAttachment(RootComponent);

}

void ANpcSpawner::BeginPlay()
{
	Super::BeginPlay();

	PoolSubsystem = GetWorld()->GetSubsystem<UPoolSubsystem>();
}

void ANpcSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PoolSubsystem || !NpcClass) return;

	int32 CurrentNpcCount = 0;
	for (TActorIterator<ANpcActor> It(GetWorld()); It; ++It)
	{
		if (*It) CurrentNpcCount++;
	}

	TArray<USceneComponent*> AvailableSpawnPoints = { SpawnNpc1, SpawnNpc2 };

	while (CurrentNpcCount < NpcCount && AvailableSpawnPoints.Num() > 0)
	{
		int32 Index = FMath::RandRange(0, AvailableSpawnPoints.Num() - 1);
		USceneComponent* SelectedSpawnPoint = AvailableSpawnPoints[Index];
		AvailableSpawnPoints.RemoveAt(Index);

		if (!SelectedSpawnPoint) continue;

		FVector SpawnLocation = SelectedSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = SelectedSpawnPoint->GetComponentRotation();

		ANpcActor* SpawnedNpc = PoolSubsystem->SpawnFromPool<ANpcActor>(NpcClass, SpawnLocation, SpawnRotation, nullptr);
        
		if (SpawnedNpc)
		{
			SpawnedNpc->InitOrder();
			CurrentNpcCount++;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Échec du spawn de NPC via le pool"));
			break;
		}
	}
}

