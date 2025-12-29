# =============================================================================
# Setup script for Windows development environment (PowerShell version)
# This script configures the project, builds it, and prepares it for running
#
# Usage: Right-click and "Run with PowerShell" or run from PowerShell:
#        Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope Process; .\setup-windows.ps1
# =============================================================================

$ErrorActionPreference = "Stop"

Write-Host ""
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Substitution Cipher - Windows Setup" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Get the directory where the script is located
$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
# Navigate to project root (two levels up from docs\setup\)
$ProjectRoot = (Get-Item $ScriptDir).Parent.Parent.FullName

Set-Location $ProjectRoot
Write-Host "Project directory: $ProjectRoot"
Write-Host ""

# Check if Git is installed
try {
    $null = git --version
    Write-Host "[OK] Git is installed" -ForegroundColor Green
} catch {
    Write-Host "[ERROR] Git is not installed or not in PATH" -ForegroundColor Red
    Write-Host ""
    Write-Host "Please install Git from https://git-scm.com/" -ForegroundColor Yellow
    Write-Host "Make sure to check 'Add to PATH' during installation" -ForegroundColor Yellow
    Read-Host "Press Enter to exit"
    exit 1
}

# Check if CMake is installed
$CmakeCmd = "cmake"
try {
    $null = cmake --version
    Write-Host "[OK] CMake is installed" -ForegroundColor Green
} catch {
    # Check for Visual Studio's CMake
    $VSCmakePaths = @(
        "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
        "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
        "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe",
        "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
    )

    $FoundCmake = $false
    foreach ($path in $VSCmakePaths) {
        if (Test-Path $path) {
            $CmakeCmd = $path
            $FoundCmake = $true
            Write-Host "[OK] CMake found in Visual Studio installation" -ForegroundColor Green
            break
        }
    }

    if (-not $FoundCmake) {
        Write-Host "[ERROR] CMake is not found" -ForegroundColor Red
        Write-Host ""
        Write-Host "Please install one of the following:" -ForegroundColor Yellow
        Write-Host "  1. CMake from https://cmake.org/download/" -ForegroundColor Yellow
        Write-Host "  2. Visual Studio Community with 'Desktop development with C++'" -ForegroundColor Yellow
        Read-Host "Press Enter to exit"
        exit 1
    }
}

# Check if a C++ compiler is available
$HasCompiler = $false
$UseMSVC = $false
$UseMinGW = $false

try {
    $null = cl /?
    $HasCompiler = $true
    $UseMSVC = $true
    Write-Host "[OK] MSVC compiler found" -ForegroundColor Green
} catch {
    try {
        $null = g++ --version
        $HasCompiler = $true
        $UseMinGW = $true
        Write-Host "[OK] MinGW G++ compiler found" -ForegroundColor Green
    } catch {
        # Try to find Visual Studio Developer environment
        $VSPaths = @(
            "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat",
            "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvarsall.bat",
            "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat",
            "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat"
        )

        foreach ($path in $VSPaths) {
            if (Test-Path $path) {
                Write-Host "[INFO] Visual Studio found at: $path" -ForegroundColor Cyan
                $HasCompiler = $true
                $UseMSVC = $true
                break
            }
        }
    }
}

if (-not $HasCompiler) {
    Write-Host "[ERROR] No C++ compiler found" -ForegroundColor Red
    Write-Host ""
    Write-Host "Please install one of the following:" -ForegroundColor Yellow
    Write-Host "  - Visual Studio Community with 'Desktop development with C++'" -ForegroundColor Yellow
    Write-Host "  - MinGW-w64 from https://www.mingw-w64.org/" -ForegroundColor Yellow
    Read-Host "Press Enter to exit"
    exit 1
}

# Configure Git for Windows
Write-Host ""
Write-Host "Configuring Git for cross-platform development..." -ForegroundColor Cyan
git config --local core.autocrlf true 2>$null
git config --local core.safecrlf warn 2>$null
Write-Host "[OK] Git configured with CRLF normalization" -ForegroundColor Green

# Normalize existing line endings
Write-Host ""
Write-Host "Normalizing line endings..." -ForegroundColor Cyan
git add --renormalize . 2>$null
$commitResult = git commit -m "Normalize line endings for cross-platform compatibility" 2>&1
if ($LASTEXITCODE -eq 0) {
    Write-Host "[OK] Line endings normalized" -ForegroundColor Green
} else {
    Write-Host "[OK] Line endings already normalized" -ForegroundColor Green
}

Write-Host ""
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Building the project..." -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

$BuildDir = Join-Path $ProjectRoot "build"

# Clean previous build if exists
if (Test-Path $BuildDir) {
    Write-Host "Cleaning previous build..."
    Remove-Item -Recurse -Force $BuildDir
}

New-Item -ItemType Directory -Path $BuildDir | Out-Null
Set-Location $BuildDir

Write-Host "Configuring with CMake..."

if ($UseMinGW) {
    & $CmakeCmd .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
    if ($LASTEXITCODE -ne 0) {
        Write-Host "[ERROR] CMake configuration failed" -ForegroundColor Red
        Read-Host "Press Enter to exit"
        exit 1
    }
    Write-Host ""
    Write-Host "Compiling..."
    mingw32-make -j$env:NUMBER_OF_PROCESSORS
    if ($LASTEXITCODE -ne 0) {
        Write-Host "[ERROR] Build failed" -ForegroundColor Red
        Read-Host "Press Enter to exit"
        exit 1
    }
    $ExePath = Join-Path $BuildDir "bin\SubstitutionCipher.exe"
} else {
    # Try Visual Studio 2022 first, then 2019
    & $CmakeCmd .. -G "Visual Studio 17 2022" -A x64
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Trying Visual Studio 2019..." -ForegroundColor Yellow
        & $CmakeCmd .. -G "Visual Studio 16 2019" -A x64
        if ($LASTEXITCODE -ne 0) {
            Write-Host "[ERROR] CMake configuration failed" -ForegroundColor Red
            Read-Host "Press Enter to exit"
            exit 1
        }
    }
    Write-Host ""
    Write-Host "Compiling..."
    & $CmakeCmd --build . --config Release
    if ($LASTEXITCODE -ne 0) {
        Write-Host "[ERROR] Build failed" -ForegroundColor Red
        Read-Host "Press Enter to exit"
        exit 1
    }
    $ExePath = Join-Path $BuildDir "bin\Release\SubstitutionCipher.exe"
}

Write-Host ""
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Setup Complete!" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

if (Test-Path $ExePath) {
    Write-Host "Build successful!" -ForegroundColor Green
    Write-Host ""
    Write-Host "The executable is located at:"
    Write-Host "  $ExePath" -ForegroundColor Yellow
    Write-Host ""

    $RunNow = Read-Host "Would you like to run the program now? (y/n)"
    if ($RunNow -eq 'y' -or $RunNow -eq 'Y') {
        Write-Host ""
        Write-Host "Starting Substitution Cipher..." -ForegroundColor Cyan
        Write-Host ""
        & $ExePath
    }
} else {
    Write-Host "[ERROR] Build failed - executable not found" -ForegroundColor Red
    Read-Host "Press Enter to exit"
    exit 1
}

Write-Host ""
Write-Host "For detailed documentation, see:" -ForegroundColor Cyan
Write-Host "  - $ProjectRoot\docs\guides\BUILD.md"
Write-Host "  - $ProjectRoot\docs\guides\WINDOWS_BUILD_GUIDE.md"
Write-Host "  - $ProjectRoot\README.md"
Write-Host ""
Read-Host "Press Enter to exit"

