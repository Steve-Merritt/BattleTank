// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
    ATank();

    virtual void BeginPlay() override;

public:

    float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    int32 StartingHealth = 100;

    UPROPERTY(VisibleAnywhere, Category = "Health")
    int32 CurrentHealth = StartingHealth;
};
