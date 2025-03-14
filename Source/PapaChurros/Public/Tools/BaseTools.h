#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTools.generated.h"

UCLASS()
class PAPACHURROS_API ABaseTools : public AActor
{
	GENERATED_BODY()

public:
	ABaseTools();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FString ToolName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	float MaxCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	bool bIsInUse;
	
	virtual void StartUse();
	
	virtual void StopUse();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	UStaticMeshComponent* ToolMesh;

protected:
	virtual void BeginPlay() override;
	
};
