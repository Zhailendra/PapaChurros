#pragma once

#include "CoreMinimal.h"
#include "BaseTools.h"
#include "Fryer.generated.h"

UCLASS()
class PAPACHURROS_API AFryer : public ABaseTools
{
	GENERATED_BODY()

public:
	AFryer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fryer")
	int ChurrosCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fryer")
	float CookingTime;

	UPROPERTY(BlueprintReadOnly, Category = "Fryer")
	bool bIsCooking;

	UFUNCTION(BlueprintCallable, Category = "Fryer")
	void AddChurros(int Amount);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Fryer")
	void StartUse() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Fryer")
	void StopUse() override;

protected:
	virtual void BeginPlay() override;
};
