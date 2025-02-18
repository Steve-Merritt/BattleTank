// Copyright Azimuth Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void IntendMoveForward(float Throw);
	
    UFUNCTION(BlueprintCallable, Category = "Input")
    void IntendTurnRight(float Throw);

private:
	// Called from the pathfinding logic of the AI controllers
	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

    UTankTrack* LeftTrack;
    UTankTrack* RightTrack;
};
