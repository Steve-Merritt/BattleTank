// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

// Enum for aiming state
UENUM()
enum class EFiringState : uint8 
{ 
    Locked,
    Aiming,
    Reloading,
    OutOfAmmo
};

// Hold's barrel's properties and methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

    void AimAt(FVector HitLocation);

    UFUNCTION(BlueprintCallable, Category = "Firing")
    void Fire();

    UFUNCTION(BlueprintCallable, Category = "Firing")
    int32 GetRoundsLeft() const;

    EFiringState GetFiringState() const;

protected:
    UTankAimingComponent();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

    void MoveBarrelTowards(const FVector& AimDirection);
    bool IsBarrelMoving();

    UTankBarrel* Barrel = nullptr;
    UTankTurret* Turret = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
    TSubclassOf<AProjectile> ProjectileBlueprint;

    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState FiringState = EFiringState::Reloading;

    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float ReloadTimeInSeconds = 0.3f;

    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float LaunchSpeed = 10000;

    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    int32 RoundsLeft = 20;

    double LastFireTime = 0;

    FVector AimDirection;
};
