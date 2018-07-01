// Copyright Azimuth Games

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn)
    {
        UE_LOG(LogTemp, Warning, TEXT("[AIController] No Player Pawn found."));
        return nullptr;
    }

    return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto ControlledTank = Cast<ATank>(GetPawn());

    if (PlayerTank)
    {
        // Move towards player
        MoveToActor(PlayerTank, AcceptanceRadius);

        // Aim towards player
        ControlledTank->AimAt(GetPlayerTank()->GetActorLocation());

        // Fire if ready
        ControlledTank->Fire();
    }
}

