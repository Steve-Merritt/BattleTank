// Copyright Azimuth Games

#include "TankTrack.h"


UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
    Super::BeginPlay();

    OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    //UE_LOG(LogTemp, Warning, TEXT("OnHit frame: %d"), GFrameNumber);
    DriveTrack();
    ApplySidewaysForce();
    CurrentThrottle = 0;
}

void UTankTrack::SetThrottle(float Throttle)
{
    CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -2, 2);
    //UE_LOG(LogTemp, Warning, TEXT("Frame %d, CThrottle:\t%f\t%s"), GFrameNumber, CurrentThrottle, *GetName());
}

void UTankTrack::DriveTrack()
{
    auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::ApplySidewaysForce()
{
    // Calculate slippage speed
    float SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

    // Calculate the required acceleration this frame to correct
    float DeltaTime = GetWorld()->GetDeltaSeconds();
    FVector CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

    // Calculate and apply sideways (F = m * a)
    auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // two tracks
    TankRoot->AddForce(CorrectionForce);
}
