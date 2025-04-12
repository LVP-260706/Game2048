#include "Grid.h"
#include <map>

std::map<int, SDL_Color> numberColors =
{
    {0,    {200, 200, 200, 255}},
    {2,    {238, 228, 218, 255}},
    {4,    {237, 224, 200, 255}},
    {8,    {237, 207, 114, 255}},
    {16,   {237, 204, 97, 255}},
    {32,   {237, 200, 80, 255}},
    {64,   {237, 197, 63, 255}},
    {128,  {237, 194, 46, 255}},
    {256,  {242, 177, 121, 255}},
    {512,  {245, 149, 99, 255}},
    {1024, {246, 124, 95, 255}},
    {2048, {246, 94, 59, 255}}
};

int board[GRID_SIZE][GRID_SIZE] =
{
    {0   , 2   , 4   , 8   },
    {16  , 32  , 64  , 128 },
    {256 , 512 , 1024, 2048},
    {0   , 0   , 0   , 0   }
};

void drawBoard(SDL_Renderer* renderer, int windowWidth, int windowHeight)
{
    int boardWidth = GRID_SIZE * CELL_SIZE + (GRID_SIZE - 1) * PADDING;
    int boardHeight = boardWidth;

    int offsetX = (windowWidth - boardWidth) / 2;
    int offsetY = (windowHeight - boardHeight) / 2;

    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            SDL_Rect cell;
            cell.x = offsetX + col * (CELL_SIZE + PADDING);
            cell.y = offsetY + row * (CELL_SIZE + PADDING);
            cell.w = CELL_SIZE;
            cell.h = CELL_SIZE;

            int value = board[row][col];
            SDL_Color color;
            if (numberColors.count(value)) color = numberColors[value];
            else color = {120, 120, 120, 255};
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(renderer, &cell);
            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
            SDL_RenderDrawRect(renderer, &cell);
        }
    }
}

