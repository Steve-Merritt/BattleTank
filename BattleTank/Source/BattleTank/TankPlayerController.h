// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
    void SetPawn(APawn* InPawn) override;
    void Tick(float DeltaTime) override;

protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void FoundAimingComponent(UTankAimingComponent* AimCompRef);

    UPROPERTY(BlueprintReadOnly)
    UTankAimingComponent* AimingComponent = nullptr;

private:
    // Start the tank moving the barrel so that a shot would hit where
    // the crosshair intersects the world.
    void AimTowardsCrosshair();

    bool GetSightRayHitLocation(FVector &OutHitLocation) const;

    bool GetLookDirection(FVector2D &ScreenLocation, FVector & OutHitLocation) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

    UPROPERTY(EditAnywhere)
    float CrosshairXLocation = 0.5;

    UPROPERTY(EditAnywhere)
    float CrosshairYLocation = 0.33333;

    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000;

    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float LaunchSpeed = 4000;

    UFUNCTION()
    void OnPossessedTankDeath();
};
