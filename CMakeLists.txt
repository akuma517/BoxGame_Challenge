cmake_minimum_required(VERSION 3.25.0)

project(asaphus_challenge VERSION 0.1.0 LANGUAGES CXX)

# Set the directory where the bin will be built.
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


set( PROJECT_HEADERS ${PROJECT_SOURCE_DIR}/src/includes/catch.hpp )
set( PROJECT_SRCS ${PROJECT_SOURCE_DIR}/src/asaphus_coding_challenge.cpp )

# Link the sources with the final binary named "challenge"
add_executable(challenge ${PROJECT_SRCS} ${PROJECT_HEADERS} )



# set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(${PROJECT_NAME} asaphus_coding_challenge.cpp catch.hpp)
