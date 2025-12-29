@echo off
REM =============================================================================
REM Setup script for Windows development environment
REM This script configures the project, builds it, and prepares it for running
REM
REM Usage: Double-click or run from Command Prompt: setup-windows.bat
REM =============================================================================

setlocal EnableDelayedExpansion

echo.
echo ========================================
echo Substitution Cipher - Windows Setup
echo ========================================
echo.

REM Get the directory where the script is located
set "SCRIPT_DIR=%~dp0"
REM Navigate to project root (two levels up from docs\setup\)
cd /d "%SCRIPT_DIR%..\.."
set "PROJECT_ROOT=%CD%"

echo Project directory: %PROJECT_ROOT%
echo.

REM Check if Git is installed
where git >nul 2>nul
if errorlevel 1 (
    echo [ERROR] Git is not installed or not in PATH
    echo.
    echo Please install Git from https://git-scm.com/
    echo Make sure to check "Add to PATH" during installation
    echo.
    pause
    exit /b 1
)
echo [OK] Git is installed

REM Check if CMake is installed
set "CMAKE_CMD=cmake"
where cmake >nul 2>nul
if errorlevel 1 (
    REM Check for Visual Studio's CMake
    if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" (
        set "CMAKE_CMD=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
        echo [OK] CMake found in Visual Studio installation
    ) else if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" (
        set "CMAKE_CMD=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
        echo [OK] CMake found in Visual Studio 2019 installation
    ) else (
        echo [ERROR] CMake is not found
        echo.
        echo Please install one of the following:
        echo   1. CMake from https://cmake.org/download/
        echo   2. Visual Studio Community with "Desktop development with C++"
        echo.
        pause
        exit /b 1
    )
) else (
    echo [OK] CMake is installed
)

REM Check if a C++ compiler is available
set "HAS_COMPILER=0"
set "USE_MSVC=0"
set "USE_MINGW=0"

where cl >nul 2>nul
if not errorlevel 1 (
    set "HAS_COMPILER=1"
    set "USE_MSVC=1"
    echo [OK] MSVC compiler found
    goto :compiler_found
)

where g++ >nul 2>nul
if not errorlevel 1 (
    set "HAS_COMPILER=1"
    set "USE_MINGW=1"
    echo [OK] MinGW G++ compiler found
    goto :compiler_found
)

REM Try to find Visual Studio Developer Command Prompt
if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" (
    echo [INFO] Initializing Visual Studio 2022 environment...
    call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul 2>nul
    set "HAS_COMPILER=1"
    set "USE_MSVC=1"
    echo [OK] MSVC compiler initialized
    goto :compiler_found
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" (
    echo [INFO] Initializing Visual Studio 2019 environment...
    call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul 2>nul
    set "HAS_COMPILER=1"
    set "USE_MSVC=1"
    echo [OK] MSVC compiler initialized
    goto :compiler_found
)

if "%HAS_COMPILER%"=="0" (
    echo [ERROR] No C++ compiler found
    echo.
    echo Please install one of the following:
    echo   - Visual Studio Community with "Desktop development with C++"
    echo   - MinGW-w64 from https://www.mingw-w64.org/
    echo.
    pause
    exit /b 1
)

:compiler_found

REM Configure Git for Windows
echo.
echo Configuring Git for cross-platform development...
git config --local core.autocrlf true 2>nul
git config --local core.safecrlf warn 2>nul
echo [OK] Git configured with CRLF normalization

REM Normalize existing line endings
echo.
echo Normalizing line endings...
git add --renormalize . 2>nul
git commit -m "Normalize line endings for cross-platform compatibility" 2>nul || echo [OK] Line endings already normalized

echo.
echo ========================================
echo Building the project...
echo ========================================
echo.

set "BUILD_DIR=%PROJECT_ROOT%\build"

REM Clean previous build if exists
if exist "%BUILD_DIR%" (
    echo Cleaning previous build...
    rmdir /s /q "%BUILD_DIR%" 2>nul
)

mkdir "%BUILD_DIR%"
cd /d "%BUILD_DIR%"

echo Configuring with CMake...
if "%USE_MINGW%"=="1" (
    "%CMAKE_CMD%" .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
    if errorlevel 1 goto :build_failed
    echo.
    echo Compiling...
    mingw32-make -j%NUMBER_OF_PROCESSORS%
    if errorlevel 1 goto :build_failed
    set "EXE_PATH=%BUILD_DIR%\bin\SubstitutionCipher.exe"
) else (
    "%CMAKE_CMD%" .. -G "Visual Studio 17 2022" -A x64
    if errorlevel 1 (
        echo Trying Visual Studio 2019...
        "%CMAKE_CMD%" .. -G "Visual Studio 16 2019" -A x64
        if errorlevel 1 goto :build_failed
    )
    echo.
    echo Compiling...
    "%CMAKE_CMD%" --build . --config Release
    if errorlevel 1 goto :build_failed
    set "EXE_PATH=%BUILD_DIR%\bin\Release\SubstitutionCipher.exe"
)

echo.
echo ========================================
echo Setup Complete!
echo ========================================
echo.

if exist "%EXE_PATH%" (
    echo Build successful!
    echo.
    echo The executable is located at:
    echo   %EXE_PATH%
    echo.

    set /p "RUN_NOW=Would you like to run the program now? (y/n): "
    if /i "!RUN_NOW!"=="y" (
        echo.
        echo Starting Substitution Cipher...
        echo.
        "%EXE_PATH%"
    )
) else (
    goto :build_failed
)

echo.
echo For detailed documentation, see:
echo   - %PROJECT_ROOT%\docs\guides\BUILD.md
echo   - %PROJECT_ROOT%\docs\guides\WINDOWS_BUILD_GUIDE.md
echo   - %PROJECT_ROOT%\README.md
echo.
pause
exit /b 0

:build_failed
echo.
echo [ERROR] Build failed. Please check the error messages above.
echo.
pause
exit /b 1
