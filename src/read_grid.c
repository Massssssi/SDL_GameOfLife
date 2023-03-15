#include<read_grid.h>
#include <stdio.h>
#include <stdlib.h>
int read_grid(char* filename, Grid* grid)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
        return 1;

    int n = fscanf(file, "%d %d", &(grid->rows), &(grid->colums));
    if (n < 2)
    {
        fclose(file);
        return 2;
    }

    grid->values = malloc(get_size(*grid));
    for(int row=0; row<grid->rows;row++)
    {
        for(int col=0;col<grid->colums;col++)
        {
            n = fscanf(file, "%d", &(grid->values[row*grid->colums+col]));
            if (n == 0)
            {
                free(grid->values);
                fclose(file);
                return 2;
            }
        }
    }
    return 0;
}
