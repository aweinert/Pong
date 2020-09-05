A simple pong clone that only serves as a playground for me to learn SDL2.
Build and execution are only tested on Windows, but should also run on Linux.
For that, the build process probably

# How to Build

- Create a directory `Engine/deps/SDL`. Copy all header files of SDL2 into that directory.
- Create a directory `Pong/libs`.
	- Copy all static libs of SDL2 into that directory, namely `SDL2`, `SDL2main` and `SDL2test`.
	- Copy the dynamically linked libraries of SDL into that directory.
- Run CMake in the main directory