// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	//How far ahead can the actor grab in cm?
	float reach = 100.0f;

	//Actor handlers
	UPhysicsHandleComponent* PhysicsHandle = nullptr; 
	UInputComponent* InputComponent = nullptr;

	// Ray-Cast and Grab what's in reach
	void Grab();
	// Release
	void GrabRelease();

	//Attach Actor Components
	void AttachActorComponents();
	const FHitResult GetFirstPhysicsBodyInReach();
};
