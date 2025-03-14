#pragma once

#include "CoreMinimal.h"
#include "BaseTools.h"
#include "Dispenser.generated.h"

UENUM(BlueprintType)
enum class EDrinkType : uint8
{
	Coca UMETA(DisplayName = "Coca"),
	Fanta UMETA(DisplayName = "Fanta"),
	Eau UMETA(DisplayName = "Eau")
};

UCLASS()
class PAPACHURROS_API ADispenser : public ABaseTools
{
	GENERATED_BODY()

public:
	ADispenser();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispenser")
	EDrinkType SelectedDrink;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispenser")
	float PouringSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Dispenser")
	float CurrentLiquidLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispenser")
	float MaxLiquidLevel;

	UPROPERTY(BlueprintReadOnly, Category = "Dispenser")
	bool bIsPouring;

	UFUNCTION(BlueprintCallable, Category = "Dispenser")
	void SelectDrink(EDrinkType NewDrink);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Dispenser")
	void StartUse() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Dispenser")
	void StopUse() override;

protected:
	virtual void BeginPlay() override;
};
