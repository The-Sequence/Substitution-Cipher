# Quick Reference: Windows Development

## 🚀 Get Started in 2 Minutes

### First Time Only
```cmd
# 1. Clone
git clone https://github.com/The-Sequence/Substitution-Cipher.git
cd Substitution-Cipher

# 2. Setup (choose one)
setup-windows.bat
# OR
powershell -ExecutionPolicy Bypass -File setup-windows.ps1

# Follow the script output!
```

### Every Build
```cmd
cd build

# Configure (first time only)
cmake .. -G "Visual Studio 17 2022"

# Build
cmake --build . --config Release

# Run
.\bin\Release\SubstitutionCipher.exe
```

---

## 📋 Prerequisites

| Tool | Download | Why |
|------|----------|-----|
| Git | https://git-scm.com | Version control |
| CMake | https://cmake.org/download | Build system |
| C++ Compiler | Visual Studio Community | Compile code |

**Easiest:** Download Visual Studio Community (includes all three)

---

## 🎯 IDE Quick Start

### Visual Studio
1. File → Open → CMake
2. Select `CMakeLists.txt`
3. Visual Studio auto-configures
4. Press F5 to run

### CLion
1. File → Open
2. Select project folder
3. CLion auto-detects CMakeLists.txt
4. Click green play button

### VS Code
1. Install CMake extension
2. Open project folder
3. Select compiler when prompted
4. Press Ctrl+Shift+B to build

---

## 🐛 Quick Troubleshooting

| Issue | Solution |
|-------|----------|
| CMake not found | Install from cmake.org |
| No compiler | Install Visual Studio Community |
| Permission denied on script | `Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope Process` |
| All files show as modified | Run setup script (handles automatically) |
| Build fails | Check `.editorconfig` settings |

---

## 📁 Important Files

| File | Purpose |
|------|---------|
| `CMakeLists.txt` | Build configuration - DO NOT MOVE |
| `.editorconfig` | Formatting rules - your IDE uses this |
| `.gitattributes` | Line ending rules - Git uses this |
| `BUILD.md` | Detailed build guide |
| `WINDOWS_BUILD_GUIDE.md` | Windows-specific help |

---

## ✅ Verify Setup

```cmd
# Check Git line ending config
git config core.autocrlf
# Should show: true

# Check files are not modified
git status
# Should show: working tree clean

# Check build works
cd build
cmake ..
cmake --build . --config Release
# Should complete without errors
```

---

## 🔗 Learn More

- **Build Instructions:** See `BUILD.md`
- **Windows Details:** See `WINDOWS_BUILD_GUIDE.md`
- **Implementation Details:** See `WINDOWS_COMPATIBILITY_FINAL_SUMMARY.md`
- **Full Summary:** See `WINDOWS_COMPATIBILITY_SETUP.md`

---

## 💬 Still Need Help?

1. Read the appropriate `.md` file above
2. Run setup script - it shows guidance
3. Check the Troubleshooting section in `BUILD.md`
4. Open an issue on GitHub with full error message

---

**Status:** Project is Windows-ready! 🎉

