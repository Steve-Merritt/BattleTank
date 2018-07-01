// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    void BeginPlay() override;

    void Tick(float DeltaTime) override;

    ATank* GetControlledTank() const;

    ATank* GetPlayerTank() const;

private:
    float AcceptanceRadius = 300;
	
};
