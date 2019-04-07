// Copyright Azimuth Games

#include "Tank.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
    Super::BeginPlay(); // Needed for BP BeginPlay

    CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
    int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

    CurrentHealth -= DamageToApply;
    if (CurrentHealth <= 0)
    {
        OnDeath.Broadcast();
    }
    return DamageToApply;
}

float ATank::GetUnitHealth() const
{
    return static_cast<float>(CurrentHealth) / static_cast<float>(StartingHealth);
}

