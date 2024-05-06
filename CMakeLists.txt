cmake_minimum_required(VERSION 3.25.0)

project(asaphus_challenge VERSION 0.1.0 LANGUAGES CXX)


# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the directory to store the executable
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/challenge)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Include directories
include_directories(includes)

#Add source files
file(GLOB HEADER_FILES "includes/*.h" "includes/*.hpp" )
file(GLOB SOURCE_FILES "src/*.cpp")

# Add executable
add_executable(AsaphusChallenge ${SOURCE_FILES} ${HEADER_FILES} )


