// Copyright Azimuth Games

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
    if (!ensure(TankAimingComponent)) { return; }
    AimingComponent = TankAimingComponent;
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!ensure(AimingComponent)) { return; }

    auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    auto ControlledTank = GetPawn();

    if (!ensure(PlayerTank && ControlledTank)) { return; }

    // Move towards player
    MoveToActor(PlayerTank, AcceptanceRadius);

    // Aim towards player
    AimingComponent->AimAt(PlayerTank->GetActorLocation());

    if (AimingComponent->GetFiringState() == EFiringState::Locked)
    {
        AimingComponent->Fire();
    }
}

