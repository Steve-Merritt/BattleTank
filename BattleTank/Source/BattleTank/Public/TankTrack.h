// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetThrottle(float Throttle);
	
    // Max force per track in Newtons
    UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; // 40 ton tank, 1g acceleration

private:
    UTankTrack();

    TArray<ASprungWheel*> GetWheels() const;

    void DriveTrack(float CurrentThrottle);
};
