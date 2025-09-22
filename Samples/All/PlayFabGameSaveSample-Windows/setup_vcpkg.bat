@echo off
setlocal EnableDelayedExpansion
echo Setting up vcpkg dependencies for Simple Game...
echo.

REM Try to find vcpkg in Visual Studio installation first
set "VCPKG_EXE="

REM Check if VSINSTALLDIR is set and use it
if defined VSINSTALLDIR (
    set "VS_VCPKG_PATH=%VSINSTALLDIR%VC\vcpkg\vcpkg.exe"
    if exist "%VS_VCPKG_PATH%" (
        set "VCPKG_EXE=%VS_VCPKG_PATH%"
        set "VCPKG_ROOT=%VSINSTALLDIR%VC\vcpkg"
        echo Found Visual Studio vcpkg at: %VS_VCPKG_PATH%
    )
)

REM Fallback to default VS 2022 paths if VSINSTALLDIR not found
if not defined VCPKG_EXE (
    set "VS_COMMUNITY_VCPKG_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg.exe"
    if exist "%VS_COMMUNITY_VCPKG_PATH%" (
        set "VCPKG_EXE=%VS_COMMUNITY_VCPKG_PATH%"
        set "VCPKG_ROOT=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg"
        echo Found Visual Studio 2022 Community vcpkg at: %VS_COMMUNITY_VCPKG_PATH%
    )
)

REM Try Visual Studio 2022 Enterprise path
if not defined VCPKG_EXE (
    echo DEBUG: Checking Enterprise path...
    set "VS_ENTERPRISE_VCPKG_PATH=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\vcpkg\vcpkg.exe"
    echo DEBUG: Testing path: "!VS_ENTERPRISE_VCPKG_PATH!"
    if exist "!VS_ENTERPRISE_VCPKG_PATH!" (
        echo DEBUG: Enterprise path exists, setting variables...
        set "VCPKG_EXE=!VS_ENTERPRISE_VCPKG_PATH!"
        set "VCPKG_ROOT=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\vcpkg"
        echo Found Visual Studio 2022 Enterprise vcpkg at: !VS_ENTERPRISE_VCPKG_PATH!
    ) else (
        echo DEBUG: Enterprise path does not exist
    )
)

REM Check VCPKG_ROOT environment variable as final fallback
if not defined VCPKG_EXE (
    if defined VCPKG_ROOT (
        if exist "%VCPKG_ROOT%\vcpkg.exe" (
            set "VCPKG_EXE=%VCPKG_ROOT%\vcpkg.exe"
            echo Found vcpkg at: %VCPKG_ROOT%\vcpkg.exe
        )
    )
)

REM Debug output
if defined VCPKG_EXE (
    echo DEBUG: VCPKG_EXE is set to: %VCPKG_EXE%
) else (
    echo DEBUG: VCPKG_EXE is not set
)

if not defined VCPKG_EXE (
    echo Error: vcpkg not found in any of the following locations:
    echo   - Visual Studio ^(VSINSTALLDIR^): %VSINSTALLDIR%VC\vcpkg\vcpkg.exe
    echo   - Visual Studio 2022 Community: C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg.exe
    echo   - Visual Studio 2022 Enterprise: C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\vcpkg\vcpkg.exe
    echo   - VCPKG_ROOT environment variable: %VCPKG_ROOT%\vcpkg.exe
    echo.
    echo Please ensure Visual Studio 2022 with C++ workload is installed,
    echo or set VCPKG_ROOT to your vcpkg installation directory.
    exit /b 1
)

echo Found vcpkg at: %VCPKG_EXE%
echo.

echo Installing packages from vcpkg.json manifest...
"%VCPKG_EXE%" install --triplet x64-windows

echo.
echo Integrating vcpkg with Visual Studio...
"%VCPKG_EXE%" integrate install

echo.
echo Setup complete! You can now build the project in Visual Studio.
echo.
echo Installed packages:
"%VCPKG_EXE%" list