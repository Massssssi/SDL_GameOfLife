#include<stdio.h>
#include<game_of_life.h>
#include<display.h>
#include<read_grid.h>
#include<save_grid.h>
#include <stdlib.h>


Grid auto_fill_grid(int rows, int columns)
{
    Grid grid;
    grid.rows = rows;
    grid.colums = columns;
    grid.values = malloc(get_size(grid));

    for(int r=0;r<grid.rows;r++)
    {
        for(int c=0;c<grid.colums;c++)
        {
            float prob = (float)rand() / RAND_MAX;
            if (prob > 0.7)
                grid.values[r * grid.colums + c] = 1;
            else
                grid.values[r * grid.colums + c] = 0;
        }
    }
    return grid;
}

int main()
{
    
    Grid grid=auto_fill_grid(100, 150);
    
    init_display(1100, 900);
    display_sdl(grid);
    for (int count = 0; count < 500; count++)
    {
        grid = get_next_state(grid);
        //_sleep(100);
        display_sdl(grid);
        if (is_stable())
            break;
    }
    close_display();
}
