# 📁 Project Organization Guide

## Quick Overview

The Substitution-Cipher project is now cleanly organized with a clear separation between active source code and legacy files.

### What's in the Root? 🎯

The **root directory** contains only the essential, active project files:

```
✅ CMakeLists.txt        - Primary build configuration (CMake)
✅ *.cpp, *.h            - Active source code
✅ README.md             - Project documentation
✅ LICENSE.txt           - MIT License
✅ docs/                 - Project documentation & setup scripts
✅ .github/              - GitHub CI/CD workflows
```

### What's in Useless/? 📦

The **Useless/** directory is a "storage" folder for legacy files:

```
❌ bestpractices1/       - Old Visual Studio project
❌ bestpractices1.sln    - Old Visual Studio solution
❌ legacy-vs/            - Old VS-specific code
❌ legacy-files/         - Legacy source code
❌ Old/                  - Archived code
❌ *.Chat History*       - Old chat/notes files
```

These files are preserved for:
- Historical reference
- Emergency fallback (if needed)
- Understanding project evolution

**They are NOT used for development.**

---

## For Developers

### Starting Development

1. **Build the project:**
   ```bash
   mkdir build && cd build
   cmake .. -DCMAKE_BUILD_TYPE=Release
   cmake --build .
   ```

2. **Or use the one-click setup:**
   ```bash
   chmod +x docs/setup/setup-macos.sh
   ./docs/setup/setup-macos.sh
   ```

3. **Edit files in the root directory** (main.cpp, choiceLogic.cpp, etc.)

4. **DO NOT** edit or reference files in `Useless/`

### Key Files to Know

| File | Purpose |
|------|---------|
| `CMakeLists.txt` | Build configuration |
| `main.cpp` | Entry point |
| `choiceLogic.cpp/h` | Encryption logic |
| `InputValidation.cpp/h` | Input handling |
| `docs/` | Documentation & setup scripts |

---

## Safe to Delete? 🗑️

**Yes!** The `Useless/` directory can be safely deleted if you have no use for legacy files. It won't affect the current project.

```bash
rm -rf Useless/
```

However, we keep it for:
- Archive/historical purposes
- Reference implementation
- Emergency fallback

---

## Next Steps

1. **Start with:** `docs/RESTRUCTURING_SUMMARY.md` for detailed changes
2. **Build with:** `docs/guides/BUILD.md` for platform-specific instructions
3. **Setup with:** `docs/setup/` scripts for one-click installation

---

**Questions? Check the README.md or docs/ folder!**

