# fastest-descent-simulation

## Installation Process
### Building Applications for MinGW-w64
**OH MY DAYS I HAVE TOILED AT THIS ISSUE FOR DAYS**
#### Building SFML Statically
```cmd
C:/msys64/mingw64/bin/g++ -fdiagnostics-color=always -std=c++17 -g src/main.cpp -IC:/SFML/include -LC:/SFML/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lwinmm -lopengl32 -lgdi32 -lfreetype -o src/main -DSFML_STATIC
```
#### Building OpenGL Statically
```cmd
C:/msys64/mingw64/bin/g++.exe -fdiagnostics-color=always -std=c++17 -g src/main.cpp 'C:/OpenGL/src/glad.c' -o src/main -LC:/OpenGL/lib -IC:/OpenGL/include -lglfw3 -lopengl32 -lgdi32
```