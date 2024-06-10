# Poisson Points Unreal Engine Plugin

## Description
The Poisson Points Plugin provides a tool to generate evenly distributed random points within a specified area using the Poisson Disk Sampling algorithm. This plugin is useful for applications requiring non-overlapping points, such as procedural content generation in games.
![1_93EtzInFnl4hZNCeYoTEVg](https://github.com/taklegko/PoissonPointsPlugin/assets/168089606/d8df883d-9c9c-4890-b068-76b272200561)


## Features
- Generate evenly distributed random points.
- Configurable parameters for point generation.
- Easy to integrate into Unreal Engine projects.

## Installation
1. **Download the Plugin:**
   - Download the Poisson Disk Sampler Plugin from the repository or marketplace.

2. **Install the Plugin:**
   - Extract the `PoissonDiskSamplerPlugin` folder into your project's `Engine/Plugins/Marketplace` directory.

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
  
    ![Снимок экрана 2024-06-10 191131](https://github.com/taklegko/PoissonPointsPlugin/assets/168089606/58b811a5-95a7-48ac-a258-4f27172d47a6)



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

#### License
This code is distributed under the MIT License.
