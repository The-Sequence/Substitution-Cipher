# Quick Reference: Linux Development

## 🚀 Get Started in 2 Minutes

### First Time Only
```bash
# 1. Clone
git clone https://github.com/The-Sequence/Substitution-Cipher.git
cd Substitution-Cipher

# 2. One-Click Setup (installs dependencies, builds, and runs)
chmod +x docs/setup/setup-linux.sh
./docs/setup/setup-linux.sh
```

### Every Build
```bash
cd build

# Configure (first time only)
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build
make -j$(nproc)

# Run
./bin/SubstitutionCipher
```

---

## 📋 Prerequisites

### Ubuntu/Debian
```bash
sudo apt update
sudo apt install -y cmake build-essential git
```

### Fedora/RHEL
```bash
sudo dnf install -y cmake gcc gcc-c++ make git
```

### Arch Linux
```bash
sudo pacman -S cmake base-devel git
```

### openSUSE
```bash
sudo zypper install -y cmake gcc gcc-c++ make git
```

**Note:** The setup script detects your distro and installs automatically!

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
3. Select "GCC" when prompted for compiler
4. Press Ctrl+Shift+B to build

### Qt Creator
1. File → Open File or Project
2. Select `CMakeLists.txt`
3. Configure project
4. Press Ctrl+R to build and run

### KDevelop
1. Project → Open/Import Project
2. Select `CMakeLists.txt`
3. Click Build button

---

## 🐛 Quick Troubleshooting

| Issue | Solution |
|-------|----------|
| CMake not found | Install via package manager |
| No compiler | Install `build-essential` (Ubuntu) or `base-devel` (Arch) |
| Permission denied on script | `chmod +x script.sh` |
| sudo required | Run with `sudo` or add to sudoers |
| Library not found | `sudo ldconfig` |

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

# Check GCC version
g++ --version
# Should show: g++ (GCC) 7+

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

# Build with verbose output
make VERBOSE=1

# Debug build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make

# Run with Valgrind (memory check)
valgrind ./bin/SubstitutionCipher

# Run with GDB (debugger)
gdb ./bin/SubstitutionCipher
```

---

## 📝 Notes for Cross-Platform Development

- Linux uses LF line endings (Unix style)
- Git is configured to preserve LF locally
- The `.gitattributes` file ensures consistent line endings across platforms
- All source files use tabs for indentation (see `.editorconfig`)

---

*For more detailed instructions, see [BUILD.md](BUILD.md)*

