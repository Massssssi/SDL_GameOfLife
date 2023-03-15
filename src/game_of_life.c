#include<game_of_life.h>
#include<stdio.h>
#include<stdlib.h>

int has_changed;
int is_stable()
{
    if (has_changed == 0)
        return 1;
    return 0;
}
int count_neighbours(Grid grid, int row, int col)
{
    int count = 0;
    for (int nrow = max(row - 1, 0); nrow <= min(row + 1, grid.rows - 1); nrow++)
    {
        for (int ncol = max(col - 1, 0); ncol <= min(col + 1, grid.colums - 1); ncol++)
        {
            if (nrow == row && ncol == col)
                continue;
            int index = nrow * grid.colums + ncol;
            count += grid.values[index];
        }
    }
    return count;
}

int check_end_game()
{

}

int play_game()
{

}

int get_cell_next_state(Grid grid, int row, int col)
{
    int count = count_neighbours(grid, row, col);
    int current_cell = grid.values[row * grid.colums + col];
    /*if (current_cell && (count < 2 || count > 3))
        return 0;
    if (!current_cell && count == 3)
        return 1;*/

    if (current_cell)
    {
        if (count < 2 || count > 3)
            return 0;
    }
    else
    {
        if (count == 3)
            return 1;
    }
    return current_cell;
}

Grid get_next_state(Grid grid)
{
    // Initialization
    Grid result;
    result.rows = grid.rows;
    result.colums = grid.colums;
    result.values = malloc(get_size(grid));

    has_changed = 0;
    for (int row = 0; row < grid.rows; row++)
    {
        for (int col = 0; col < grid.colums; col++)
        {
            int index = row * result.colums + col;
            int next_value = get_cell_next_state(grid, row, col);
            int old_value = grid.values[row * grid.colums + col];
            if (next_value != old_value)
                has_changed = 1;
            result.values[index] = next_value;
        }
    }
    return result;
}

int get_size(Grid grid)
{
    return sizeof(int) * grid.colums * grid.rows;
}
