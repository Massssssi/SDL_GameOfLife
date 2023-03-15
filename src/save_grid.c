#include<save_grid.h>

int save_grid(char* filename, Grid grid)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
        return 1;

    int n = fprintf(file, "%d %d", grid.rows, grid.colums);
    if (n < 0)
    {
        fclose(file);
        return 2;
    }

    for (int row = 0; row < grid.rows; row++)
    {
        for (int col = 0; col < grid.colums; col++)
        {
            n = fprintf(file, " %d", grid.values[row * grid.colums + col]);
            if (n < 0)
            {
                fclose(file);
                return 2;
            }
        }
    }
    fclose(file);
    return 0;
}
