// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
    ATank();

    virtual void BeginPlay() override;

public:

    float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

    UFUNCTION(BlueprintPure, Category = "Health")
    float GetUnitHealth() const;

    FTankDelegate OnDeath;

private:

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    int32 StartingHealth = 100;

    UPROPERTY(VisibleAnywhere, Category = "Health")
    int32 CurrentHealth;
};
