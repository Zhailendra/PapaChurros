#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Food/BaseFood.h"
#include "BaseOrder.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PAPACHURROS_API UBaseOrder : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBaseOrder();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetNbAliment(int NbAliment_) { this->NbAliment = NbAliment_; }
	int GetNbAliment() const { return NbAliment; }

	void SetHasDrink(bool bHasDrink_) { this->bHasDrink = bHasDrink_; }
	bool GetHasDrink() const { return bHasDrink; }

	void AddAliment(ABaseFood* Aliment) { Aliments.Add(Aliment); }

	UFUNCTION(BlueprintCallable)
	TArray<ABaseFood*> GetAliments() const { return Aliments; }

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	int NbAliment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	bool bHasDrink = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TArray<ABaseFood*> Aliments;
};
