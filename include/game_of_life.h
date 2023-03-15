
#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_



#include<stdio.h>

typedef struct Grid
{
    int* values;
    int rows;
    int colums;
}Grid;

//int count_neighbours(Grid grid, int row, int col)

//int check_end_game();

Grid get_next_state(Grid grid);
int get_size(Grid grid);
int is_stable();
//int play_game();

#endif // !GAME_OF_LIFE_H_
