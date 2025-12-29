# Quick Reference: macOS Development

## 🚀 Get Started in 2 Minutes

### First Time Only
```bash
# 1. Clone
git clone https://github.com/The-Sequence/Substitution-Cipher.git
cd Substitution-Cipher

# 2. One-Click Setup (installs dependencies, builds, and runs)
chmod +x docs/setup/setup-macos.sh
./docs/setup/setup-macos.sh
```

### Every Build
```bash
cd build

# Configure (first time only)
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build
make -j$(sysctl -n hw.ncpu)

# Run
./bin/SubstitutionCipher
```

---

## 📋 Prerequisites

| Tool | Install Command | Why |
|------|-----------------|-----|
| Homebrew | `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"` | Package manager |
| CMake | `brew install cmake` | Build system |
| Xcode CLI Tools | `xcode-select --install` | C++ compiler (Clang) |
| Git | `brew install git` | Version control |

**Note:** The setup script installs all of these automatically!

---

## 🎯 IDE Quick Start

### CLion
1. File → Open
2. Select project folder
3. CLion auto-detects CMakeLists.txt
4. Click green play button

### VS Code
1. Install "CMake" and "C/C++ Extension Pack" extensions
2. Open project folder
3. Select "Clang" when prompted for compiler
4. Press Cmd+Shift+B to build

### Xcode
```bash
# Generate Xcode project
cd Substitution-Cipher
mkdir build-xcode && cd build-xcode
cmake .. -G Xcode

# Open in Xcode
open SubstitutionCipher.xcodeproj
```

---

## 🐛 Quick Troubleshooting

| Issue | Solution |
|-------|----------|
| CMake not found | `brew install cmake` |
| No compiler | `xcode-select --install` |
| Homebrew not found | See Prerequisites above |
| Permission denied on script | `chmod +x script.sh` |
| Build fails on Apple Silicon | Ensure you have arm64 compatible tools |

---

## 📁 Important Files

| File | Purpose |
|------|---------|
| `CMakeLists.txt` | Build configuration - DO NOT MOVE |
| `.editorconfig` | Formatting rules - your IDE uses this |
| `.gitattributes` | Line ending rules - Git uses this |
| `docs/guides/BUILD.md` | Detailed build guide |

---

## ✅ Verify Setup

```bash
# Check CMake version
cmake --version
# Should show: cmake version 3.24+

# Check Clang version
clang --version
# Should show: Apple clang version 14+

# Check Git line ending config
git config core.autocrlf
# Should show: input

# Check files are not modified
git status
```

---

## 🔧 Useful Commands

```bash
# Clean build
cd build && make clean && make

# Full rebuild
rm -rf build && mkdir build && cd build && cmake .. && make

# Run with verbose output
./bin/SubstitutionCipher

# Check for memory leaks (if you have leaks tool)
leaks --atExit -- ./bin/SubstitutionCipher
```

---

## 📝 Notes for Cross-Platform Development

- macOS uses LF line endings (Unix style)
- Git is configured to preserve LF locally
- The `.gitattributes` file ensures consistent line endings across platforms
- All source files use tabs for indentation (see `.editorconfig`)

---

*For more detailed instructions, see [BUILD.md](BUILD.md)*

