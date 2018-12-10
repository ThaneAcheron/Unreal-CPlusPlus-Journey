// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/Public/DrawDebugHelpers.h"
#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	//Get Player View Point 
	FVector PlayerViewPoint; 
	FRotator PlayerViewPoinRotation; 

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPoint, OUT PlayerViewPoinRotation);

	FVector LineTraceEnd =  PlayerViewPoint + PlayerViewPoinRotation.Vector()  * reach;

	UE_LOG(LogTemp, Warning, TEXT("Location: ViewPoint %s || Rotation: Rotation %s"), *PlayerViewPoint.ToString(), *PlayerViewPoinRotation.ToString());

	//Debug
	DrawDebugLine(GetWorld(), PlayerViewPoint, LineTraceEnd, FColor(255,0,0), false, 0.0f, 0, 10.f);
	
	//LineTrace Raycast
	FHitResult LineTraceHit; 

	FCollisionQueryParams TraceParam(FName(TEXT("")), false, GetOwner());
	//SetUp Query param
	GetWorld()->LineTraceSingleByObjectType(OUT LineTraceHit, PlayerViewPoint, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParam);

	AActor *hitActor = LineTraceHit.GetActor();
	if (hitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("You hit %s"), *hitActor->GetName());
	}
}

