# CMakeList.txt : CMake project for Engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(PONG)

link_libraries(engine)

link_directories(libs)
link_libraries(SDL2)
link_libraries(SDL2main)
link_libraries(SDL2test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable (pong "Pong.cpp" "Pong.h")

# TODO: Add tests and install targets if needed.
