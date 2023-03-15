
#include<game_of_life.h>
#include <SDL.h>

SDL_Surface* dst;
int _width, _height;
SDL_Window* display_window;

void display_sdl(Grid grid)
{
    SDL_Rect fullrect = { 0,0 ,_width,_height  };
    SDL_FillRect(dst, &fullrect, 0);
    int w = _width/grid.colums, h = _height/grid.rows;
    int w2 = w - 2;
    int h2 = h - 2;
    Uint32 color = 0xFF00FF;
    for (int row = 0; row < grid.rows; row++)
    {
        for (int column = 0; column < grid.colums; column++)
        {
            //Uint32 color = 0;
            if (grid.values[row * grid.colums + column])
            {
                SDL_Rect rect = { column * w + 1,row * h + 1 ,h2,w2 };
                SDL_FillRect(dst, &rect, color);
            }
        }
    }
    SDL_UpdateWindowSurface(display_window);
    SDL_ShowWindow(display_window);
    SDL_Delay(40);
}

void init_display(int width, int height)
{
    SDL_Init(SDL_INIT_VIDEO);
    _width = width;
    _height = height;
    display_window = SDL_CreateWindow("Game of life", 50, 50, width, height, 0);
    dst = SDL_GetWindowSurface(display_window);
}

void close_display()
{
    SDL_FreeSurface(dst);
    SDL_DestroyWindow(display_window);
    SDL_Quit();
}
void display(Grid grid)
{
    for(int row=0;row<grid.rows;row++)
    {
        for(int column = 0; column<2*grid.colums+1;column++)
            printf("-");
        printf("\n|");
        for(int column =0;column<grid.colums;column++)
        {
            if(grid.values[row * grid.colums + column])
                printf("+|");
            else
                printf(" |");
        }
        printf("\n");
    }
    for (int column = 0; column < 2 * grid.colums + 1; column++)
        printf("-");
    printf("\n");
}
