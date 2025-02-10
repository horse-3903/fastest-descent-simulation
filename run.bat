@echo off
REM Navigate to the project directory
cd /d %~dp0
set /p "filename=Enter the name of the file you want to run: "

REM Compile the program
echo Compiling "%filename%"
C:/msys64/mingw64/bin/g++.exe -fdiagnostics-color=always -g "%filename%" "src/collision.cpp" "src/util.cpp" -o "final.exe" -LC:/SFML/lib -IC:/SFML/include -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lwinmm -lopengl32 -lgdi32 -lfreetype -DSFML_STATIC

REM Check if the compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b %errorlevel%
)

REM Run the compiled executable
echo Running "final.exe"
"final.exe"