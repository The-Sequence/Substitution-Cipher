# Substitution Cipher

A cross-platform C++ console application that implements a simple substitution cipher for text encryption and decryption.

![C/C++ CI](https://github.com/The-Sequence/Substitution-Cipher/workflows/C/C++%20CI/badge.svg)

## 🚀 Quick Start

### One-Click Setup

Choose the script for your operating system:

| Platform | Script | Command |
|----------|--------|---------|
| **macOS** | `docs/setup/setup-macos.sh` | `chmod +x docs/setup/setup-macos.sh && ./docs/setup/setup-macos.sh` |
| **Linux** | `docs/setup/setup-linux.sh` | `chmod +x docs/setup/setup-linux.sh && ./docs/setup/setup-linux.sh` |
| **Windows (CMD)** | `docs/setup/setup-windows.bat` | Double-click or run `docs\setup\setup-windows.bat` |
| **Windows (PowerShell)** | `docs/setup/setup-windows.ps1` | `Set-ExecutionPolicy Bypass -Scope Process; .\docs\setup\setup-windows.ps1` |

The setup scripts will:
1. ✅ Install required dependencies (CMake, compiler)
2. ✅ Configure Git for cross-platform development
3. ✅ Build the project
4. ✅ Optionally run the application

### Manual Build

```bash
# Clone the repository
git clone https://github.com/The-Sequence/Substitution-Cipher.git
cd Substitution-Cipher

# Create build directory
mkdir build && cd build

# Configure and build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .

# Run (path varies by platform)
./bin/SubstitutionCipher          # macOS/Linux
.\bin\Release\SubstitutionCipher.exe  # Windows
```

## ✨ Features

- **Encrypt text** using a 52-character substitution key
- **Decrypt text** back to original plaintext
- **View current key** being used for encryption
- **Generate new random keys** using Fisher-Yates shuffle algorithm
- **Set custom encryption keys** for specific use cases
- **Chat history logging** - saves encryption sessions to file

## 📖 How It Works

The substitution cipher replaces each letter in the alphabet with a corresponding letter from a key:

```
Original:  abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
Key:       xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ

Example:   "Hello" → "Kmyyo"
```

## 📁 Project Structure

```
Substitution-Cipher/
├── main.cpp              # Application entry point
├── choiceLogic.cpp       # Encryption/decryption logic
├── ChoiceLogic.h         # Header for choice logic
├── InputValidation.cpp   # User input handling
├── InputValidation.h     # Header for input validation
├── CMakeLists.txt        # CMake build configuration
├── README.md             # This file
├── LICENSE.txt           # MIT License
├── docs/
│   ├── guides/           # Documentation guides
│   │   ├── BUILD.md      # Detailed build instructions
│   │   ├── WINDOWS_BUILD_GUIDE.md
│   │   └── ...
│   └── setup/            # One-click setup scripts
│       ├── setup-macos.sh
│       ├── setup-linux.sh
│       ├── setup-windows.bat
│       └── setup-windows.ps1
└── .github/
    └── workflows/        # CI/CD configuration
```

## 🛠️ Requirements

- **CMake** 3.24 or higher
- **C++17** compatible compiler:
  - GCC 7+ (Linux)
  - Clang 5+ / Xcode Command Line Tools (macOS)
  - MSVC 2019+ / Visual Studio (Windows)

## 📚 Documentation

| Document | Description |
|----------|-------------|
| [BUILD.md](docs/guides/BUILD.md) | Comprehensive build instructions for all platforms |
| [WINDOWS_BUILD_GUIDE.md](docs/guides/WINDOWS_BUILD_GUIDE.md) | Windows-specific setup guide |
| [WINDOWS_QUICK_REFERENCE.md](docs/guides/WINDOWS_QUICK_REFERENCE.md) | Quick reference for Windows developers |

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📜 License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

## 🙏 Acknowledgments

- First proper GitHub project! Created on August 9, 2023 (Wednesday)
- Uses the classic substitution cipher technique for educational purposes

---

*Last updated: December 2024*
