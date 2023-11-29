cmake_minimum_required(VERSION 3.24)
project(cmake_cpp_project_template
        VERSION      1.0.0
        LANGUAGES    CXX
        DESCRIPTION  "My DPP Bot with CMake"
        HOMEPAGE_URL "https://dpp.dev")


add_subdirectory(3rd-party/)

# Project properties target sets
# all the required features and definitions.
add_library(project_properties
        INTERFACE)
# Set the standard library version to c++20.
# List of all available C++ features:
# https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
target_compile_features(project_properties
        INTERFACE cxx_std_20)
target_compile_definitions(project_properties
        INTERFACE)

# Bot executable
add_executable(bot
        src/main.cpp)
target_link_libraries(bot
        PUBLIC project_properties
        PRIVATE dpp)

add_custom_command(
        TARGET bot POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "$<TARGET_PROPERTY:dpp,BINARY_DIR>/"
        "$<TARGET_PROPERTY:bot,BINARY_DIR>/"
)
