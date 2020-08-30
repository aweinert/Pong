# CMakeList.txt : CMake project for Engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(pong)

# Add source to this project's executable.
add_executable (pong "Pong.cpp" "Pong.h")
target_link_libraries(pong PUBLIC engine)

# TODO: Add tests and install targets if needed.
