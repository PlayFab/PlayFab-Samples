@echo off
echo Building Simple Game...
echo.

REM Check if Visual Studio is available
where msbuild >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: MSBuild not found. Please run this from a Visual Studio Developer Command Prompt.
    echo Or make sure Visual Studio Build Tools are installed and in PATH.
    pause
    exit /b 1
)

REM Build the solution
echo Building solution...
msbuild PlayFabGameSaveSample.sln /p:Configuration=Debug /p:Platform=x64

if %errorlevel% equ 0 (
    echo.
    echo Build successful!
    echo Executable location: x64\Debug\PlayFabGameSaveSample.exe
    echo.
    echo You can now run the game!
) else (
    echo.
    echo Build failed. Please check the error messages above.
    echo Make sure vcpkg dependencies are installed correctly.
)
