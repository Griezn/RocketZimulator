# CMakeList.txt : CMake project for RocketZimulator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(MSVC_VERSION MSVC14)

# Add source to this project's executable.
add_executable (RocketZimulator  "main.cpp" "environment.cpp" "environment.h" "texture_manager.cpp" "texture_manager.h" "rocket.cpp" "rocket.h"   "background.cpp" "background.h")

#copies binary into code instead of dll's
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/sdk/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

include_directories(c:/sdk/SFML-2.5.1/include)
target_link_libraries(RocketZimulator sfml-system sfml-window sfml-graphics sfml-network sfml-audio)