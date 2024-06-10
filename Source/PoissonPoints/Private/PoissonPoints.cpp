// Copyright (c) 2024 Marina Eremina
// This code is distributed under the MIT License.

#include "PoissonPoints.h"
#include "Math/UnrealMathUtility.h"

#define LOCTEXT_NAMESPACE "FPoissonPointsModule"
#define LOCTEXT_NAMESPACE "UPoissonPoints"

void FPoissonPointsModule::StartupModule()
{}

void FPoissonPointsModule::ShutdownModule()
{}

TArray<FVector2D> UPoissonPoints::GeneratePoissonPoints(float Width, float Height, float Radius, int32 MaxAttempts)
{
    TArray<FVector2D> ActivePoints;
    TArray<FVector2D> Points;

    float CellSize = Radius / FMath::Sqrt(2.0f);
    int32 GridWidth = FMath::CeilToInt(Width / CellSize);
    int32 GridHeight = FMath::CeilToInt(Height / CellSize);

    TArray<FVector2D> Grid;
    Grid.SetNumZeroed(GridWidth * GridHeight);

    auto GetCellCoords = [CellSize](const FVector2D& Point) -> FIntPoint {
        return FIntPoint(FMath::FloorToInt(Point.X / CellSize), FMath::FloorToInt(Point.Y / CellSize));
    };

    FVector2D InitialPoint(FMath::FRandRange(0.0f, Width), FMath::FRandRange(0.0f, Height));
    ActivePoints.Add(InitialPoint);
    Points.Add(InitialPoint);
    Grid[GetCellCoords(InitialPoint).Y * GridWidth + GetCellCoords(InitialPoint).X] = InitialPoint;

    while (ActivePoints.Num() > 0)
    {
        int32 Index = FMath::RandRange(0, ActivePoints.Num() - 1);
        FVector2D Point = ActivePoints[Index];
        bool bFound = false;

        for (int32 i = 0; i < MaxAttempts; i++)
        {
            FVector2D NewPoint = GenerateRandomPointAround(Point, Radius, Radius, 2 * Radius);
            if (IsValidPoint(NewPoint, Radius, Grid, GridWidth, GridHeight, CellSize))
            {
                ActivePoints.Add(NewPoint);
                Points.Add(NewPoint);
                Grid[GetCellCoords(NewPoint).Y * GridWidth + GetCellCoords(NewPoint).X] = NewPoint;
                bFound = true;
                break;
            }
        }

        if (!bFound)
        {
            ActivePoints.RemoveAt(Index);
        }
    }

    return Points;
}

FVector2D UPoissonPoints::GenerateRandomPointAround(const FVector2D& Point, float Radius, float MinDist, float MaxDist)
{
    float Angle = FMath::FRandRange(0.0f, 2 * PI);
    float Dist = FMath::FRandRange(MinDist, MaxDist);
    return FVector2D(Point.X + Dist * FMath::Cos(Angle), Point.Y + Dist * FMath::Sin(Angle));
}

bool UPoissonPoints::IsValidPoint(const FVector2D& Point, float Radius, const TArray<FVector2D>& Grid, int32 GridWidth, int32 GridHeight, float CellSize)
{
    if (Point.X < 0 || Point.X >= GridWidth * CellSize || Point.Y < 0 || Point.Y >= GridHeight * CellSize)
    {
        return false;
    }

    auto GetCellCoords = [CellSize](const FVector2D& Point) -> FIntPoint {
        return FIntPoint(FMath::FloorToInt(Point.X / CellSize), FMath::FloorToInt(Point.Y / CellSize));
    };

    FIntPoint Cell = GetCellCoords(Point);
    int32 SearchStartX = FMath::Max(Cell.X - 2, 0);
    int32 SearchStartY = FMath::Max(Cell.Y - 2, 0);
    int32 SearchEndX = FMath::Min(Cell.X + 2, GridWidth - 1);
    int32 SearchEndY = FMath::Min(Cell.Y + 2, GridHeight - 1);

    for (int32 x = SearchStartX; x <= SearchEndX; x++)
    {
        for (int32 y = SearchStartY; y <= SearchEndY; y++)
        {
            FVector2D Neighbor = Grid[y * GridWidth + x];
            if (Neighbor != FVector2D::ZeroVector)
            {
                float Dist = FVector2D::Distance(Point, Neighbor);
                if (Dist < Radius)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPoissonPointsModule, PoissonPoints)