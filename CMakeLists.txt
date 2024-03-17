cmake_minimum_required(VERSION 3.28)
project(SummerStl VERSION 0.0.1)
string(TIMESTAMP COMPILE_TIME %Y%m%d-%H%M%S)

set(CMAKE_CXX_STANDARD 23)

message("Project Name: ${PROJECT_NAME}")
message("Project binary dir: ${PROJECT_BINARY_DIR}")
message("Project source dir: ${PROJECT_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)
message("Runtime output dir: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
#message("Library output dir: ${PROJECT_OUTPUT_PATH}")

# ut
add_subdirectory(${PROJECT_SOURCE_DIR}/vector)
