// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/PrimitiveComponent.h"
#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	AttachActorComponents();	
}

void UGrabber::AttachActorComponents()
{
	//Physcis Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
	}
	else {
		UE_LOG(LogTemp, Error, TEXT(" %s is missing a Physics Handler!"), *GetOwner()->GetName());
	}

	//Input Controller
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		//Bind actor input 
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::GrabRelease);
	}
	else {

	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Variables to store Player View Point 
	FVector PlayerViewPoint;
	FRotator PlayerViewPoinRotation;

	//Reference the player and store the viewport data
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPoint, OUT PlayerViewPoinRotation);
	FVector LineTraceEnd = PlayerViewPoint + PlayerViewPoinRotation.Vector()  * reach;

	//LINE TRACE if the physcis handle is attached 
	  //Move the object that we're holding
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}

}

void UGrabber::Grab() {
	//raycast 
	UE_LOG(LogTemp, Warning, TEXT("Grab Key Presses"));
	//Try reach any actors with collision channel set
	GetFirstPhysicsBodyInReach();
	//if we hit something then attach a phys handle 
	//TODO
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor(); 

	if (ActorHit != nullptr)
	{
		PhysicsHandle->GrabComponent(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation(), true);
	}
}

void UGrabber::GrabRelease() {
	UE_LOG(LogTemp, Warning, TEXT("Grab Key Released"));

	//TODO Release physics handle
	PhysicsHandle->ReleaseComponent();
}

//Raycast and return a hit result
const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	//Variables to store Player View Point 
	FVector PlayerViewPoint;
	FRotator PlayerViewPoinRotation;

	//Reference the player and store the viewport data
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPoint, OUT PlayerViewPoinRotation);
	FVector LineTraceEnd = PlayerViewPoint + PlayerViewPoinRotation.Vector()  * reach;

	//Debug
	//DrawDebugLine(GetWorld(), PlayerViewPoint, LineTraceEnd, FColor(255,0,0), false, 0.0f, 0, 10.f);

	//LineTrace Raycast
	FHitResult LineTraceHit;

	//Raycast type declaration
	FCollisionQueryParams TraceParam(FName(TEXT("")), false, GetOwner());
	//SetUp Query param
	GetWorld()->LineTraceSingleByObjectType(OUT LineTraceHit, PlayerViewPoint, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParam);

	AActor *hitActor = LineTraceHit.GetActor();
	if (hitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("You hit %s"), *hitActor->GetName());
	}

	return LineTraceHit;
}