// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
    TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
    TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::AimAt(FVector HitLocation)
{
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
    UE_LOG(LogTemp, Warning, TEXT("Firing!"));
}

