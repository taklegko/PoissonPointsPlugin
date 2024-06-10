// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PoissonPoints.generated.h"

class FPoissonPointsModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};


/**
 * UPoissonPoints for generating evenly distributed random points using the Poisson Disk Sampling algorithm.
 */
UCLASS(BlueprintType)
class POISSONPOINTS_API UPoissonPoints : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	* Generates evenly distributed random points within a specified area using the Poisson Disk Sampling algorithm.
	*
	* @param Width The width of the area in which to generate points.
	* @param Height The height of the area in which to generate points.
	* @param Radius The minimum distance between any two points.
	* @param MaxAttempts The maximum number of attempts to generate a valid point around an existing point before it is considered inactive (default is 30).
	* @return An array of FVector2D containing the generated points.
	*
	* Example usage:
	* @code
	* TArray<FVector2D> Points = UPoissonPointsBPLibrary::GeneratePoissonPoints(500.0f, 500.0f, 20.0f, 30);
	* @endcode
	*/
	UFUNCTION(BlueprintCallable, Category = "PoissonPoints")
	static TArray<FVector2D> GeneratePoissonPoints(float Width = 1000, float Height = 1000, float Radius = 50, int32 MaxAttempts = 15);

private:
	static FVector2D GenerateRandomPointAround(const FVector2D& Point, float Radius, float MinDist, float MaxDist);
	static bool IsValidPoint(const FVector2D& Point, float Radius, const TArray<FVector2D>& Grid, int32 GridWidth, int32 GridHeight, float CellSize);

	
};
