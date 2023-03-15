#include "game_of_life_tests.h"

#include <stdlib.h>
#include "../include/game_of_life.h"

void get_size_should_return_zero_when_grid_is_empty(void) {
    //test stuff
    Grid grid;
    grid.rows = 0;
    grid.colums = 0;
    TEST_ASSERT_EQUAL(0, get_size(grid));
}

void get_size_test(void)
{
    Grid grid;
    grid.rows = 5;
    grid.colums = 10;
    TEST_ASSERT_EQUAL(200, get_size(grid));
}

void is_stable_should_return_true_when_called_first(void)
{
    TEST_ASSERT(is_stable());
}
void is_stable_should_return_true_when_called_on_clear_grid(void)
{
    Grid grid;
    grid.rows = 3;
    grid.colums = 3;
    grid.values = malloc(get_size(grid));
    for(int row=0;row<grid.rows;row++)
    {
        for(int col=0;col<grid.colums;col++)
        {
            grid.values[row * grid.colums + col] = 0;
        }
    }
    get_next_state(grid);
    TEST_ASSERT(is_stable());
}

void get_next_state_should_return_clear_grid(void)
{
    Grid grid;
    grid.rows = 3;
    grid.colums = 3;
    grid.values = malloc(get_size(grid));
    for (int row = 0; row < grid.rows; row++)
    {
        for (int col = 0; col < grid.colums; col++)
        {
            grid.values[row * grid.colums + col] = 0;
        }
    }
    grid.values[1 * grid.colums + 1] = 1;

    grid = get_next_state(grid);

    TEST_ASSERT(!is_stable());

    TEST_ASSERT_EACH_EQUAL_INT(0, grid.values, grid.colums * grid.rows);
}
// not needed when using generate_test_runner.rb
