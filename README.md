# SDL_GameOfLife
This project is an implementation of John Conway's Game of Life using the Simple DirectMedia Layer (SDL) library in C.The Game of Life is a cellular automaton simulation that operates on a grid of cells, where each cell can either be alive or dead. The simulation evolves according to a set of rules that determine the next state of each cell based on its neighbors.

# Prerequisites
Visual Studio
CMake
SDL2
downdload SDL2.

# Installation
Install Visual Studio from the official website.
Install CMake by downloading the installer from the official website.
Install the SDL2 Library by following the installation instructions from the official website. If you are using visual studio as your code editor make sure you download the correct zip i.e(SDL2-devel-x.xx.x-VC.zip).

# build instructions
important things to do before building the project:
-make sure that your you include the SDL2 folder in your envirement variables (CMAKE_PREFIX_PATH).
-after generating the build for of the project, navigate to the lib folder of the SDL2 folder you have downloaded and copy the SDL2.dll file and paste it insidre the build folder.
