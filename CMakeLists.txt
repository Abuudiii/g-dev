cmake_minimum_required(VERSION 3.16)
project(SFMLGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML 2.x (Homebrew)
set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS graphics window system audio network REQUIRED)

# Include src directory for headers
include_directories(src)

# Create executable from source files
add_executable(game main.cpp src/Game.cpp src/Player.cpp)

# Link SFML libraries (SFML 2 uses sfml- prefix)
target_link_libraries(game sfml-graphics sfml-window sfml-system sfml-audio sfml-network)