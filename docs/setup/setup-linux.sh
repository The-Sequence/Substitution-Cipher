#!/bin/bash
# =============================================================================
# Setup script for Linux development environment
# This script configures the project, builds it, and prepares it for running
#
# Usage: ./setup-linux.sh
# =============================================================================

set -e  # Exit on error

echo ""
echo "========================================"
echo "Substitution Cipher - Linux Setup"
echo "========================================"
echo ""

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# Navigate to project root (two levels up from docs/setup/)
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

cd "$PROJECT_ROOT"
echo "Project directory: $PROJECT_ROOT"
echo ""

# Detect Linux distribution
if [ -f /etc/os-release ]; then
    . /etc/os-release
    OS=$NAME
else
    echo "WARNING: Unable to detect Linux distribution"
    OS="Unknown"
fi

echo "Detected OS: $OS"
echo ""

# Function to check if command exists
command_exists() {
    command -v "$1" &> /dev/null
}

# Update package lists
echo "Updating package lists..."
if command_exists apt; then
    sudo apt update
elif command_exists dnf; then
    sudo dnf check-update || true
elif command_exists pacman; then
    sudo pacman -Sy
elif command_exists zypper; then
    sudo zypper refresh
fi

# Install CMake
if ! command_exists cmake; then
    echo "Installing CMake..."
    if command_exists apt; then
        sudo apt install -y cmake
    elif command_exists dnf; then
        sudo dnf install -y cmake
    elif command_exists pacman; then
        sudo pacman -S --noconfirm cmake
    elif command_exists zypper; then
        sudo zypper install -y cmake
    fi
    echo "[OK] CMake installed"
else
    echo "[OK] CMake is installed ($(cmake --version | head -n1))"
fi

# Install GCC/G++ or Clang
if ! command_exists g++; then
    echo "Installing GCC/G++..."
    if command_exists apt; then
        sudo apt install -y build-essential
    elif command_exists dnf; then
        sudo dnf install -y gcc gcc-c++ make
    elif command_exists pacman; then
        sudo pacman -S --noconfirm base-devel
    elif command_exists zypper; then
        sudo zypper install -y gcc gcc-c++ make
    fi
    echo "[OK] GCC/G++ installed"
else
    echo "[OK] C++ compiler found ($(g++ --version | head -n1))"
fi

# Verify Git is installed
if ! command_exists git; then
    echo "Installing Git..."
    if command_exists apt; then
        sudo apt install -y git
    elif command_exists dnf; then
        sudo dnf install -y git
    elif command_exists pacman; then
        sudo pacman -S --noconfirm git
    elif command_exists zypper; then
        sudo zypper install -y git
    fi
    echo "[OK] Git installed"
else
    echo "[OK] Git is installed ($(git --version))"
fi

# Configure Git for Linux (use 'input' mode for LF preservation)
echo ""
echo "Configuring Git for cross-platform development..."
git config --local core.autocrlf input 2>/dev/null || true
git config --local core.safecrlf warn 2>/dev/null || true

echo "[OK] Git configured with proper line ending handling"

# Normalize existing line endings (only if in a git repo)
if [ -d ".git" ]; then
    echo ""
    echo "Normalizing line endings..."
    git add --renormalize . 2>/dev/null || true
    git commit -m "Normalize line endings for cross-platform compatibility" 2>/dev/null || echo "[OK] Line endings already normalized"
fi

# Create and configure build directory
echo ""
echo "========================================"
echo "Building the project..."
echo "========================================"
echo ""

BUILD_DIR="$PROJECT_ROOT/build"

# Clean previous build if exists
if [ -d "$BUILD_DIR" ]; then
    echo "Cleaning previous build..."
    rm -rf "$BUILD_DIR"
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

echo "Configuring with CMake..."
cmake .. -DCMAKE_BUILD_TYPE=Release

echo ""
echo "Compiling..."
make -j$(nproc)

echo ""
echo "========================================"
echo "✅ Setup Complete!"
echo "========================================"
echo ""

# Check if build was successful
if [ -f "$BUILD_DIR/bin/SubstitutionCipher" ]; then
    echo "🎉 Build successful!"
    echo ""
    echo "The executable is located at:"
    echo "  $BUILD_DIR/bin/SubstitutionCipher"
    echo ""
    echo "To run the program:"
    echo "  cd $BUILD_DIR/bin"
    echo "  ./SubstitutionCipher"
    echo ""

    # Ask if user wants to run the program now
    read -p "Would you like to run the program now? (y/n): " -n 1 -r
    echo ""
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        echo ""
        echo "Starting Substitution Cipher..."
        echo ""
        "$BUILD_DIR/bin/SubstitutionCipher"
    fi
else
    echo "❌ Build failed. Please check the error messages above."
    exit 1
fi

echo ""
echo "For detailed documentation, see:"
echo "  - $PROJECT_ROOT/docs/guides/BUILD.md"
echo "  - $PROJECT_ROOT/README.md"
echo ""
