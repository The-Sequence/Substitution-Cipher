# Building on Windows

This guide helps you build the Substitution Cipher project on Windows.

## Prerequisites

### Option 1: Using CMake (Recommended)

1. **Install CMake**
   - Download from https://cmake.org/download/
   - Choose "Windows x86_64 Installer"
   - During installation, select "Add CMake to the system PATH"

2. **Install a C++ Compiler**
   
   **Option A: Visual Studio (Full IDE)**
   - Download Visual Studio Community from https://visualstudio.microsoft.com/
   - During installation, select "Desktop development with C++"
   - This includes MSVC compiler and CMake integration

   **Option B: MinGW (Lightweight)**
   - Download from https://www.mingw-w64.org/
   - Add to PATH or use CMake to specify compiler location

3. **Install Git**
   - Download from https://git-scm.com/
   - During installation, ensure "Configurable Git line endings" is set to "Checkout as-is, commit as-is"

### Option 2: Using Visual Studio Project (Legacy)

- Look in `Useless/` directory for legacy `.vcxproj` files
- These are kept for reference but not recommended

## Building Steps

### Method 1: Command Line with CMake

```bash
# 1. Clone the repository (if not already done)
git clone https://github.com/The-Sequence/Substitution-Cipher.git
cd Substitution-Cipher

# 2. Create build directory
mkdir build
cd build

# 3. Generate build system
cmake .. -G "Visual Studio 17 2022"
# Or for MinGW:
# cmake .. -G "MinGW Makefiles"

# 4. Build
cmake --build . --config Release

# 5. Run
.\bin\Release\SubstitutionCipher.exe
# Or for MinGW:
# .\bin\SubstitutionCipher.exe
```

### Method 2: Using CLion IDE

1. Open CLion
2. File → Open → Select the Substitution-Cipher folder
3. CLion will automatically detect CMakeLists.txt
4. Click the green run button to build and execute

### Method 3: Using Visual Studio

1. In Visual Studio, select File → Open → CMake
2. Navigate to and open CMakeLists.txt in the Substitution-Cipher folder
3. Visual Studio will automatically configure the project
4. Select Build → Build All
5. Press F5 to run

## Troubleshooting

### Issue: "cmake: command not found"
**Solution:** CMake is not in your PATH. Add it manually or reinstall and select "Add to PATH"

### Issue: "No C++ compiler found"
**Solution:** Install Visual Studio Community with "Desktop development with C++" workload

### Issue: Line ending problems (CRLF vs LF)
**Solution:** This project is configured to handle this automatically via `.gitattributes`. If you still have issues:
```bash
# Reset line endings
git add --renormalize .
git commit -m "Normalize line endings"
```

### Issue: Build fails with "permission denied"
**Solution:** On some systems, you may need to run commands with admin privileges or adjust folder permissions

## Notes

- The project uses **C++17** standard
- It's configured to work on Windows, macOS, and Linux
- All source files use **LF line endings** (Unix style) for cross-platform compatibility
- **CRLF** is only used for Visual Studio project files
- The `.editorconfig` file ensures consistent formatting in all IDEs

## After Building

The compiled executable will be in:
- **CMake (Release):** `build/bin/Release/SubstitutionCipher.exe`
- **CMake (MinGW):** `build/bin/SubstitutionCipher.exe`
- **Visual Studio:** `build/Release/SubstitutionCipher.exe`

## Cross-Platform Development

To ensure smooth development across Windows, macOS, and Linux:
1. Always use `git config core.autocrlf true` (already configured globally)
2. Let `.gitattributes` handle line ending normalization
3. Use `.editorconfig` for consistent formatting
4. Test your changes on Windows before pushing

For questions or issues, open an issue on GitHub!

