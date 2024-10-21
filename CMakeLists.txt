cmake_minimum_required(VERSION 3.20)

set(TARGET_NAME project)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 20)

project("${TARGET_NAME}" VERSION 1.0 LANGUAGES CXX)

# Source files
file(GLOB TARGET_SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
add_library("${TARGET_NAME}" STATIC ${TARGET_SRC_FILES})
target_include_directories("${TARGET_NAME}" PUBLIC src)

# Main application
add_executable("${TARGET_NAME}_main" src/neural_net.cpp)
target_link_libraries("${TARGET_NAME}_main" PRIVATE "${TARGET_NAME}")

# Catch2 dependency (commented out since you don't have tests yet)
# include(FetchContent)
# FetchContent_Declare(
#   Catch2
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG        v3.5.3
# )
# FetchContent_MakeAvailable(Catch2)
# include(Catch)

# Enable testing (commented out since you don't have tests yet)
# enable_testing()
# catch_discover_tests("${TARGET_NAME}_tests")
