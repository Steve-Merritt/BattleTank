// Copyright Azimuth Games


#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Physics Constraint"));
    SetRootComponent(PhysicsConstraint);

    Chassis = CreateDefaultSubobject<UStaticMeshComponent>(FName("Chassis"));
    Chassis->SetupAttachment(PhysicsConstraint);

    Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
    Wheel->SetupAttachment(PhysicsConstraint);
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

    if (GetAttachParentActor())
    {
        UE_LOG(LogTemp, Warning, TEXT("Not NULL %s"), *GetAttachParentActor()->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("NULL"));
    }
	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

