
#ifndef DISPLAY_H_
#define DISPLAY_H_




#include<stdio.h>

#include "game_of_life.h"

void display(Grid grid);
void init_display(int width, int height);
void close_display();
void display_sdl(Grid grid);

#endif // !DISPLAY_H_