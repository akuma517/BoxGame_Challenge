cmake_minimum_required(VERSION 3.25.0)
project(asaphus_challenge VERSION 0.1.0 LANGUAGES CXX)

# Set the directory where the bin will be built.
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/challenge)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Include directories
include_directories(includes)

file(GLOB HEADER_FILES "includes/*.h" "includes/*.hpp" )
file(GLOB SOURCE_FILES "src/*.cpp")

# Add executable
add_executable(AsaphusChallenge ${SOURCE_FILES} ${HEADER_FILES} )


