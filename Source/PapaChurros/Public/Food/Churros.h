#pragma once

#include "CoreMinimal.h"
#include "Food/BaseFood.h"
#include "Churros.generated.h"

UCLASS()
class PAPACHURROS_API AChurros : public ABaseFood
{
	GENERATED_BODY()

public:
	AChurros();

	virtual void Tick(float DeltaTime) override;
	
protected:

	virtual void BeginPlay() override;
	
private:

};
