// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

    void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
    ATank* GetControlledTank() const;

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
};
