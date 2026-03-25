cmake_minimum_required(VERSION 3.10)
project(robot)

include_directories(include)

add_executable(robot
    src/main.cpp
    src/robot.cpp
    src/robotair.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)