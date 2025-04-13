#ifndef GRID_H
#define GRID_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <map>
#include <vector>
using namespace std;

const int GRID_SIZE = 4;
const int CELL_SIZE = 100;
const int PADDING = 1;

extern int board[GRID_SIZE][GRID_SIZE];

struct Cell
{
    int value;
    SDL_Rect rect;
};

void drawBoard(SDL_Renderer* renderer, int windowWidth, int windowHeight, TTF_Font* font);
void drawNumber(SDL_Renderer* renderer, TTF_Font* font, const Cell& cell);
#endif // GRID_H
