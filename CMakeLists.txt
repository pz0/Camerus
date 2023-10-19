cmake_minimum_required(VERSION 3.10)
project(camerus)

set(CMAKE_CXX_COMPILER g++)

add_subdirectory(core)

find_package(OpenCV REQUIRED)

add_executable(camerus main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(camerus camerus_core)