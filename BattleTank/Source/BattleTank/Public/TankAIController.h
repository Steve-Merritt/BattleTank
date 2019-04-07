// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    void BeginPlay() override;
    void SetPawn(APawn* InPawn) override;
    void Tick(float DeltaTime) override;

protected:
    UPROPERTY(BlueprintReadOnly)
    UTankAimingComponent* AimingComponent = nullptr;

    UPROPERTY(EditAnywhere, Category = "Setup")
    float AcceptanceRadius = 8000;

private:
    UFUNCTION()
    void OnPossessedTankDeath();

};
