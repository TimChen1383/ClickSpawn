// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickSpawn.h"

#include "ActorToSpawn.h"


// Sets default values
AClickSpawn::AClickSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClickSpawn::BeginPlay()
{
	Super::BeginPlay();
	
	FOnTimelineFloat TimelineProgress;
	TimelineProgress.BindDynamic(this, &AClickSpawn::SqeezeActor);
	Timeline.AddInterpFloat(TimeCurve, TimelineProgress);
	
}

// Called every frame
void AClickSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timeline.TickTimeline(DeltaTime);

}

void AClickSpawn::ClickSpawn()
{

	APlayerController* CurrentPlayer = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//Get mouse clicked location and rotation
	FVector MouseLocation;
	FVector MouseDirection;
	CurrentPlayer->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);

	//Do line trace to find the hit location
	FHitResult HitResult;
	FVector StartLoc = MouseLocation;
	FVector EndLoc = MouseLocation + (MouseDirection*TraceDistance);
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLoc, EndLoc, ECC_Visibility);

	//Draw debug line for visualization
	DrawDebugLine(GetWorld(), StartLoc, EndLoc, FColor::Red, true, 0.0f, 0, 0.0f);

	//Spawn actor at mouse hit points
	FVector HitLocation = HitResult.ImpactPoint;
	GEngine->AddOnScreenDebugMessage(-1,1.0f,FColor::Orange,FString::Printf(TEXT("Spawn Location %s"),*HitLocation.ToString()));
	FRotator HitRotation = FRotator(0,0,0);
	FActorSpawnParameters SpawnInfo;
	SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, HitLocation, HitRotation, SpawnInfo);
	Timeline.PlayFromStart();
	//SpawnedActor->SetActorScale3D(FVector(5,1,1));
	
}

void AClickSpawn::SqeezeActor(float Value)
{
	SpawnedActor->SetActorScale3D(FVector(Value*SqueezeValue, Value*SqueezeValue, Value*SqueezeValue));
}


// How can I get some meshes' surface points and spawn on it?
