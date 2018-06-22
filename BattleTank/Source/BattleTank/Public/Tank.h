// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* BarrelToSet);

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurretReference(UTankTurret* TurretToSet);

    void AimAt(FVector HitLocation);
    
    UFUNCTION(BlueprintCallable, Category = Actions)
    void Fire();

protected:
    UTankAimingComponent* TankAimingComponent = nullptr;

private:
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100000; // TODO: find sensible default
	
};
