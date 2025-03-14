#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NpcSpawner.generated.h"

class UPoolSubsystem;
class ANpcActor;

UCLASS()
class PAPACHURROS_API ANpcSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ANpcSpawner();
	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Npc Class")
	TSubclassOf<ANpcActor> NpcClass;

private:
	UPROPERTY()
	UPoolSubsystem* PoolSubsystem;

	UPROPERTY(EditAnywhere, Category = "Properties")
	int NpcCount = 3;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	USceneComponent* RootSceneComponent;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	USceneComponent* SpawnNpc1;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	USceneComponent* SpawnNpc2;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	USceneComponent* SpawnNpc3;
};
