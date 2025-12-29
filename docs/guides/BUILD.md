# Building the Substitution Cipher Project

This project is designed to work seamlessly across Windows, macOS, and Linux.

## Quick Start

### macOS / Linux (Command Line)

```bash
# Clone the repository
git clone https://github.com/The-Sequence/Substitution-Cipher.git
cd Substitution-Cipher

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Run
./bin/SubstitutionCipher
```

### Windows (Command Line with CMake)

```cmd
# Clone the repository
git clone https://github.com/The-Sequence/Substitution-Cipher.git
cd Substitution-Cipher

# Create build directory
mkdir build
cd build

# Configure with Visual Studio
cmake .. -G "Visual Studio 17 2022"

# Build
cmake --build . --config Release

# Run
.\bin\Release\SubstitutionCipher.exe
```

### Using an IDE

#### CLion (All Platforms)
1. Open CLion
2. File → Open → Select project folder
3. CLion auto-detects `CMakeLists.txt`
4. Click green play button to build and run

#### Visual Studio (Windows)
1. File → Open → CMake
2. Select `CMakeLists.txt`
3. Build → Build All (Ctrl+Shift+B)
4. Press F5 to run

#### VS Code (All Platforms)
1. Install "CMake" extension by Twxylor
2. Install "C/C++ Extension Pack" by Microsoft
3. Open the project folder
4. Select your compiler when prompted
5. Use Ctrl+Shift+B to build

## Requirements

### All Platforms
- **CMake 3.24+** (or use IDE that bundles it)
- **C++17 compatible compiler**

### Specific Compilers
- **Windows:** MSVC 2019+ (Visual Studio) or MinGW-w64
- **macOS:** Clang (comes with Xcode Command Line Tools)
- **Linux:** GCC or Clang

### Install Prerequisites

**macOS:**
```bash
brew install cmake
xcode-select --install  # Install Xcode Command Line Tools
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt update
sudo apt install cmake build-essential
```

**Windows:**
- Download Visual Studio Community (includes CMake and MSVC)
- Or separately install CMake from https://cmake.org/download/

## Project Structure

```
Substitution-Cipher/
├── CMakeLists.txt           # Build configuration
├── ChoiceLogic.h            # Header file
├── choiceLogic.cpp          # Encryption/decryption logic
├── InputValidation.h        # Header file
├── InputValidation.cpp      # User input validation
├── main.cpp                 # Main application
├── README.md                # Project overview
├── LICENSE.txt              # MIT License
├── WINDOWS_BUILD_GUIDE.md   # Windows-specific guide
├── BUILD.md                 # This file
├── .editorconfig            # Editor formatting rules
├── .gitattributes           # Git line ending configuration
├── .gitignore               # Git ignore rules
├── .github/workflows/       # CI/CD configuration
└── Useless/                 # Legacy files and archives
```

## Build Process Explained

1. **CMake Configuration Phase**
   - Detects your compiler
   - Checks for C++17 support
   - Sets up build directories
   - Generates platform-specific build files

2. **Build Phase**
   - Compiles source files
   - Links object files
   - Creates executable in `build/bin/`

3. **Output**
   - Executable: `build/bin/[platform-dependent path]/SubstitutionCipher`

## Advanced Options

### Build Types

```bash
# Debug build (with debug symbols)
cmake .. -DCMAKE_BUILD_TYPE=Debug

# Release build (optimized, smaller size)
cmake .. -DCMAKE_BUILD_TYPE=Release
```

### Specific Compiler

```bash
# Use GCC
cmake .. -DCMAKE_CXX_COMPILER=g++

# Use Clang
cmake .. -DCMAKE_CXX_COMPILER=clang++

# Use MSVC (Windows)
cmake .. -G "Visual Studio 17 2022"
```

### Verbose Build

```bash
cmake --build . --verbose
```

## Troubleshooting

### CMake not found
**Solution:** Install CMake or add to PATH

### No suitable compiler found
**Solution:** Install a C++17 compatible compiler (MSVC, GCC, or Clang)

### Permission denied on Linux
**Solution:** The build output directory may have permission issues
```bash
chmod -R u+w build/
```

### Line ending issues (especially on Windows)
**Solution:** Git is configured to handle this automatically via `.gitattributes`
```bash
git config core.autocrlf true
git add --renormalize .
```

### Build fails on macOS with "clang: error: unsupported option"
**Solution:** Update Xcode Command Line Tools
```bash
xcode-select --install
```

## Cleaning Up

```bash
# Remove build directory
rm -rf build/          # macOS/Linux
rmdir /s build         # Windows Command Prompt
```

Then rebuild from scratch following the Quick Start instructions.

## Platform-Specific Guides

- **For Windows users:** See [WINDOWS_BUILD_GUIDE.md](WINDOWS_BUILD_GUIDE.md) and [WINDOWS_QUICK_REFERENCE.md](WINDOWS_QUICK_REFERENCE.md)
- **For macOS users:** See [MACOS_QUICK_REFERENCE.md](MACOS_QUICK_REFERENCE.md)
- **For Linux users:** See [LINUX_QUICK_REFERENCE.md](LINUX_QUICK_REFERENCE.md)

## Continuous Integration

This project uses GitHub Actions to automatically build on:
- Ubuntu (Linux)
- Windows
- macOS

Check `.github/workflows/c-cpp.yml` for CI/CD configuration.

## FAQ

**Q: Can I use a different C++ version?**
A: Yes, edit `CMakeLists.txt` line 6: `set(CMAKE_CXX_STANDARD 20)` for C++20, etc.

**Q: Is there a precompiled binary?**
A: Not yet. Binaries would need to be built for each platform and architecture.

**Q: Can I use Make instead of CMake?**
A: You can use any build system, but CMake is recommended for cross-platform support.

**Q: Does this work with Code::Blocks or Dev-C++?**
A: These IDEs are outdated. Consider CLion, Visual Studio, or VS Code instead.

## Contributing

When contributing, ensure:
1. Code compiles on Windows, macOS, and Linux
2. Line endings are handled correctly (`.gitattributes` does this automatically)
3. Code follows the style defined in `.editorconfig`
4. No platform-specific absolute paths are used

## Support

For build issues:
1. Check this BUILD.md file
2. See WINDOWS_BUILD_GUIDE.md for Windows-specific help
3. Open an issue on GitHub with:
   - Your operating system and version
   - Compiler and version
   - CMake version
   - Full error message

