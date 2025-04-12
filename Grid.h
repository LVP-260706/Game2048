#ifndef GRID_H
#define GRID_H

#include <SDL.h>
const int GRID_SIZE = 4;
const int CELL_SIZE = 100;
const int PADDING = 1;

extern int board[GRID_SIZE][GRID_SIZE];

void drawBoard(SDL_Renderer* renderer, int windowWidth, int windowHeight);
#endif // GRID_H
