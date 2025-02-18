// Copyright Azimuth Games

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();  

    auto TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
    if (!ensure(TankAimingComponent)) { return; }
    FoundAimingComponent(TankAimingComponent);
    AimingComponent = TankAimingComponent;
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
    Super::SetPawn(InPawn);

    if (InPawn)
    {
        auto PossessedTank = Cast<ATank>(InPawn);
        if (!ensure(PossessedTank)) return;

        // Subscribe our local method to the tank's death event
        PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossessedTankDeath);
    }
}

void ATankPlayerController::OnPossessedTankDeath()
{
    StartSpectatingOnly();
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!ensure(AimingComponent)) { return; }

    FVector HitLocation;  // Out parameter
    bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
    if (bGotHitLocation)
    {
        AimingComponent->AimAt(HitLocation);
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
    // Find the crosshair position
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

    // "De-project" the screen position of the crosshair to a world direction
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        // Line-trace along that look direction, and see what we hit (up to max range)
        return GetLookVectorHitLocation(LookDirection, OutHitLocation);
    }

    return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D &ScreenLocation, FVector& LookDirection) const
{
    FVector CameraWorldLocation;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
    FHitResult HitResult;
    FVector StartLocation = PlayerCameraManager->GetCameraLocation();
    FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel(
        HitResult,
        StartLocation,
        EndLocation,
        ECollisionChannel::ECC_Camera))
    {
        HitLocation = HitResult.Location;
        return true;
    }

    HitLocation = FVector(0);
    return false;
}
