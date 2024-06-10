# Possion Points Unreal Engine Plugin

## Description
The Possion Points Plugin provides a tool to generate evenly distributed random points within a specified area using the Poisson Disk Sampling algorithm. This plugin is useful for applications requiring non-overlapping points, such as procedural content generation in games.

## Features
- Generate evenly distributed random points.
- Configurable parameters for point generation.
- Easy to integrate into Unreal Engine projects.

## Installation
1. **Download the Plugin:**
   - Download the Poisson Disk Sampler Plugin from the repository or marketplace.

2. **Install the Plugin:**
   - Extract the `PoissonDiskSamplerPlugin` folder into your project's `Plugins` directory.

3. **Enable the Plugin:**
   - Open your Unreal Engine project.
   - Go to `Edit` -> `Plugins`.
   - Find the `Poisson Disk Sampler Plugin` and enable it.
   - Restart the editor if prompted.

## Usage
1. **Include the Plugin:**
   - Ensure the plugin is enabled in your project.

2. **Using in Blueprints:**
   - Open any Blueprint where you want to use the Poisson Disk Sampling.
   - Add the `GeneratePoissonPoints` node from the Poisson Points category.
   - Set the parameters for Width, Height, Radius, and MaxAttempts.
   - The function will return an array of `FVector2D` containing the generated points.

3. **Using in C++:**
   - Include the `PoissonPoints.h` header in your C++ file:
     ```cpp
     #include "PoissonPoints.h"
     ```
   - Call the `GeneratePoissonPoints` function:
     ```cpp
     TArray<FVector2D> Points = UPoissonPoints::GeneratePoissonPoints(1000.0f, 1000.0f, 30.0f, 15);
     ```

## API Reference

### `GeneratePoissonPoints`

#### Parameters:
- `float Width`: The width of the area in which to generate points.
- `float Height`: The height of the area in which to generate points.
- `float Radius`: The minimum distance between any two points.
- `int32 MaxAttempts`: The maximum number of attempts to generate a valid point around an existing point before it is considered inactive (default is 30).

#### Returns:
- `TArray<FVector2D>`: An array of `FVector2D` containing the generated points.

#### Example:
```cpp
TArray<FVector2D> Points = UPoissonPoints::GeneratePoissonPoints(12345, 500.0f, 500.0f, 20.0f, 30);
```