// Copyright Azimuth Games

#include "Tank.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
    Super::BeginPlay(); // Needed for BP BeginPlay
}

