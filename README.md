<div align="center">

# Fastest Descent Simulation

Interactive C++ simulation of the Brachistochrone problem with SFML-powered real-time visualisation

[![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![SFML](https://img.shields.io/badge/SFML-8CC445?style=flat-square&logo=sfml&logoColor=white)](https://www.sfml-dev.org/)
[![License](https://img.shields.io/github/license/horse-3903/fastest-descent-simulation?style=flat-square)](LICENSE)
[![Last Commit](https://img.shields.io/github/last-commit/horse-3903/fastest-descent-simulation?style=flat-square)](../../commits)

</div>

---

## Overview

The **Brachistochrone problem**: Greek for "shortest time", asks: what curve between two points allows a ball to descend purely under gravity in the least time? The classical answer is a **cycloid**. This project simulates a ball rolling down a configurable ramp, visualises its real-time physics (position, velocity), and uses an evolutionary algorithm to optimise the ramp angle toward the fastest descent time.

---

## Features

- **Real-Time Physics Simulation**: Ball motion with gravity, velocity decomposition, and ramp collision modelled frame-by-frame
- **Live Data Window**: Separate SFML window displaying global time, ball motion time, and velocity components updated each frame
- **Evolutionary Optimisation**: Genetic-style optimisation searches for the ramp configuration that minimises descent time
- **Configurable Parameters**: Ramp start/end positions, ball radius, gravitational acceleration, and window dimensions all in `constants.h`

---

## Tech Stack

[![C++17](https://img.shields.io/badge/C++17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![SFML](https://img.shields.io/badge/SFML-8CC445?style=for-the-badge&logo=sfml&logoColor=white)](https://www.sfml-dev.org/)

---

## Getting Started

### Prerequisites

- MinGW-w64 (`g++` with C++17 support)
- [SFML](https://www.sfml-dev.org/download.php) installed at `C:/SFML/`

### Installation

Clone the repository:
```bash
git clone https://github.com/horse-3903/fastest-descent-simulation.git
cd fastest-descent-simulation
```

### Usage

**Option A: Run the pre-built batch script:**
```cmd
run.bat
```

**Option B: Compile manually with SFML (static linking):**
```cmd
C:/msys64/mingw64/bin/g++ -fdiagnostics-color=always -std=c++17 -g src/main.cpp ^
  -IC:/SFML/include -LC:/SFML/lib ^
  -lsfml-graphics-s -lsfml-window-s -lsfml-system-s ^
  -lwinmm -lopengl32 -lgdi32 -lfreetype ^
  -o src/main -DSFML_STATIC
```

Then run the compiled binary:
```cmd
src\main.exe
```

---

## Methodology

### Physics Model

The simulation models a ball sliding along a straight ramp inclined at angle `θ` under gravitational acceleration `g`. At each frame with time step `Δt`:

- **Along-ramp acceleration** decomposes gravity into tangential and normal components
- **Velocity update**: `vx += sin(θ)·cos(θ)·g·Δt`, `vy += sin²(θ)·g·Δt`
- **Free-fall** applies when the ball is not in contact with the ramp: `vy += g·Δt`
- Collision detection checks whether the ball's position intersects the ramp segment each frame

### Evolutionary Optimisation

An evolutionary algorithm iterates over candidate ramp angles:

1. **Initialise** a population of ramp configurations with varying angles
2. **Simulate** each configuration and record descent time
3. **Select** configurations with shorter descent times
4. **Mutate and recombine** to generate the next generation
5. **Repeat** until convergence: the ramp angle approaches the Brachistochrone optimum

---

## Project Structure

```
fastest-descent-simulation/
├── src/
│   ├── main.cpp            # Entry point, simulation loop, SFML rendering
│   ├── ball.cpp            # Ball physics and drawing
│   ├── collision.cpp       # Ramp collision detection
│   └── util.cpp            # Info window and helpers
├── include/
│   ├── ball.h
│   ├── collision.h
│   ├── constants.h         # Simulation parameters
│   └── util.h
├── run.bat                 # Build and run script
└── todo.txt
```

---

## License

This project is licensed under the [MIT License](LICENSE).
