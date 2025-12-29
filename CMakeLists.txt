cmake_minimum_required(VERSION 3.24)
project(SubstitutionCipher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Cross-platform compiler settings
if(MSVC)
  # Windows-specific compiler settings
  add_compile_options(/W4)  # Warning level 4
  add_compile_options(/permissive-)  # Strict standards conformance
else()
  # GCC/Clang settings
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Create executable
add_executable(SubstitutionCipher
        main.cpp
        choiceLogic.cpp
        InputValidation.cpp
)

# Set output directory for executables (cross-platform)
set_target_properties(SubstitutionCipher PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Windows-specific executable properties
if(WIN32)
  set_target_properties(SubstitutionCipher PROPERTIES
    WIN32_EXECUTABLE OFF  # Console application
  )
endif()

