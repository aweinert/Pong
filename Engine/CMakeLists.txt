# CMakeList.txt : CMake project for Engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(engine)

# Add source to this project's executable.
add_library (engine "Engine.cpp")

target_include_directories(engine PUBLIC include)

# TODO: Add tests and install targets if needed.
