#!/bin/bash
# =============================================================================
# Setup script for macOS development environment
# This script configures the project, builds it, and prepares it for running
#
# Usage: ./setup-macos.sh
# =============================================================================

set -e  # Exit on error

echo ""
echo "========================================"
echo "Substitution Cipher - macOS Setup"
echo "========================================"
echo ""

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# Navigate to project root (two levels up from docs/setup/)
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

cd "$PROJECT_ROOT"
echo "Project directory: $PROJECT_ROOT"
echo ""

# Check if Homebrew is installed
if ! command -v brew &> /dev/null; then
    echo ""
    echo "Homebrew is not installed. Installing Homebrew..."
    echo ""
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

    # Add Homebrew to PATH for Apple Silicon Macs
    if [[ $(uname -m) == 'arm64' ]]; then
        echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
        eval "$(/opt/homebrew/bin/brew shellenv)"
    fi
    echo "[OK] Homebrew installed"
else
    echo "[OK] Homebrew is installed"
fi

# Check and install CMake
if ! command -v cmake &> /dev/null; then
    echo ""
    echo "Installing CMake..."
    brew install cmake
    echo "[OK] CMake installed"
else
    echo "[OK] CMake is installed ($(cmake --version | head -n1))"
fi

# Check if Xcode Command Line Tools are installed
if ! command -v clang &> /dev/null; then
    echo ""
    echo "Xcode Command Line Tools not found. Installing..."
    xcode-select --install
    echo ""
    echo "Please wait for the installation to complete, then run this script again."
    exit 1
else
    echo "[OK] Clang compiler found ($(clang --version | head -n1))"
fi

# Verify Git is installed
if ! command -v git &> /dev/null; then
    echo ""
    echo "Installing Git..."
    brew install git
    echo "[OK] Git installed"
else
    echo "[OK] Git is installed ($(git --version))"
fi

# Configure Git for macOS (use 'input' mode for LF preservation)
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
make -j$(sysctl -n hw.ncpu)

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
