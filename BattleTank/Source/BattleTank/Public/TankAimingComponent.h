// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8 { Locked, Aiming, Reloading };

// Forward Declaration
class UTankBarrel;
class UTankTurret;

// Hold's barrel's properties and methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

    void SetBarrelReference(UTankBarrel* BarrelToSet);
    void SetTurretReference(UTankTurret* TurretToSet);

    void AimAt(FVector HitLocation, float LaunchSpeed);
	
protected:
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringStatus FiringStatus = EFiringStatus::Aiming;

private:
    UTankBarrel* Barrel = nullptr;
    UTankTurret* Turret = nullptr;

    void MoveBarrelTowards(const FVector& AimDirection);
};
