@echo off
REM Navigate to the project directory
cd /d %~dp0

REM Compile the program
C:/msys64/mingw64/bin/g++.exe -fdiagnostics-color=always -g "src/old.cpp" "src/collision.cpp" "src/util.cpp" -o "src/old.exe" -LC:/SFML/lib -IC:/SFML/include -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lwinmm -lopengl32 -lgdi32 -lfreetype -DSFML_STATIC

REM Check if the compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b %errorlevel%
)

REM Run the compiled executable
"src/old.exe"