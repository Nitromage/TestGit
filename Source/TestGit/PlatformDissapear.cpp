// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformDissapear.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"
#include "Gameframework/Actor.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UPlatformDissapear::UPlatformDissapear()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlatformDissapear::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlatformDissapear::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
	if (CheckPressure())
	{
		UE_LOG(LogTemp, Warning, TEXT("Trigger"));
	}
	else
	{
		//onCloseRequest.Broadcast();
	}
}
bool UPlatformDissapear::CheckPressure() {
	float totalMass = 0.0f;
	TArray<AActor*> overlappingActors;
	pressurePlate->GetOverlappingActors(OUT overlappingActors);
	for (int i = 0; i < overlappingActors.Num(); i++) { totalMass += overlappingActors[i]->FindComponentByClass<UPrimitiveComponent>()->GetMass(); }
	return totalMass >= 25;
}

