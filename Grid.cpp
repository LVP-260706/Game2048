#include "Grid.h"

map<int, SDL_Color> numberColors =
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

int board[GRID_SIZE][GRID_SIZE] = {0};

void drawNumber(SDL_Renderer* renderer, TTF_Font* font, const Cell& cell)
{
    if (cell.value == 0) return;

    SDL_Color textColor = {50, 50, 50, 255};
    string text = to_string(cell.value);

    SDL_Surface* textSurfare = TTF_RenderText_Blended(font, text.c_str(), textColor);
    if (!textSurfare) return;

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurfare);
    if (!textTexture)
    {
        SDL_FreeSurface(textSurfare);
        return;
    }

    int textWidth = textSurfare->w;
    int textHeight = textSurfare->h;
    SDL_Rect textRect;
    textRect.x = cell.rect.x + (cell.rect.w - textWidth) / 2;
    textRect.y = cell.rect.y + (cell.rect.h - textHeight) / 2;
    textRect.w = textWidth;
    textRect.h = textHeight;

    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurfare);
    SDL_DestroyTexture(textTexture);
}

void drawBoard(SDL_Renderer* renderer, int windowWidth, int windowHeight, TTF_Font* font)
{
    int boardWidth = GRID_SIZE * CELL_SIZE + (GRID_SIZE - 1) * PADDING;
    int boardHeight = boardWidth;

    int offsetX = (windowWidth - boardWidth) / 2;
    int offsetY = (windowHeight - boardHeight) / 2 + 55;

    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            SDL_Rect cellRect;
            cellRect.x = offsetX + col * (CELL_SIZE + PADDING);
            cellRect.y = offsetY + row * (CELL_SIZE + PADDING);
            cellRect.w = CELL_SIZE;
            cellRect.h = CELL_SIZE;

            int value = board[row][col];
            SDL_Color color;
            if (numberColors.count(value)) color = numberColors[value];
            else color = {120, 120, 120, 255};
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(renderer, &cellRect);
            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
            SDL_RenderDrawRect(renderer, &cellRect);

            Cell cell = {value, cellRect};
            drawNumber(renderer, font, cell);
        }
    }
}

void renderScore(SDL_Renderer* renderer, TTF_Font* font, int score, int x, int y)
{
    SDL_Color color = {255, 255, 255};
    string text = to_string(score);
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int textW, textH;
    SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
    SDL_Rect textRect = {x - textW / 2, y - textH / 2 + 12, textW, textH};
    SDL_RenderCopy(renderer, texture, NULL, &textRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
