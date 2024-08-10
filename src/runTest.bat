@echo off
rem Set the directory containing the .bat file as the working directory
cd /d "%~dp0"

rem Compile the source code
gcc -I..\include -L..\lib -o main.exe main.c glad.c shader\shader.c world\world.c -lglfw3 -lgdi32 -lopengl32 -Iinclude -lm

rem Check for compilation errors
if %ERRORLEVEL% NEQ 0 (
    echo Compilation failed
    exit /b %ERRORLEVEL%
)

rem Run the executable
start "" "main.exe"
