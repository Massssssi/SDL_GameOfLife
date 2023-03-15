cmake_minimum_required(VERSION 3.10)

# set the project name
project(game_of_life C)

# Let's tell it a bit about our environment
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)


# Find SDL2 library and include directories
find_package(SDL2 REQUIRED)


# Add an executable target to the project
add_executable(${PROJECT_NAME} 
		src/main.c
    		src/read_grid.c
		src/display.c
		src/save_grid.c
		src/game_of_life.c
		include/game_of_life.h	
		include/read_grid.h
		include/display.h
		include/save_grid.h
)

target_include_directories(game_of_life PUBLIC ${SDL2_INCLUDE_DIRS} src)


target_include_directories(${PROJECT_NAME}  PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main)

