// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TimelineComponent.h"
#include "ClickSpawn.generated.h"

UCLASS()
class UECPP_PRACTICE_API AClickSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClickSpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable, Category="ClickSpawn")
	void ClickSpawn();

	UPROPERTY(EditAnywhere, Category="ClickSpawn")
	float TraceDistance = 10000.0f;

	UPROPERTY(EditAnywhere, Category="ClickSpawn")
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere, Category="Magic Door")
	UCurveFloat* TimeCurve = nullptr;

	UPROPERTY(EditAnywhere, Category="ClickSpawn")
	float SqueezeValue = 1.0f;
	
	FTimeline Timeline;

	UFUNCTION()
	void SqeezeActor(float Value);

	AActor* SpawnedActor;

	
};
