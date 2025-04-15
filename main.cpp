#include "Window.h"
#include "Image.h"
#include "Grid.h"
#include "Logic.h"

#include <string>
using namespace std;
const int SCREEN_WIDTH = 700, SCREEN_HEIGHT = 650;

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

int main(int argc, char* argv[])
{
    Window window("Game 2048", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.getRenderer();
    Image image("Image/2048_mainImage.png", renderer);
    Image scoreBox("Image/score.png", renderer);
    Image bestBox("Image/best.png", renderer);

    TTF_Font* font = TTF_OpenFont("Image/Roboto-Regular.ttf", 25);
    if (!font)
    {
        cerr << TTF_GetError() << endl;
        return -1;
    }

    bool running = true;
    bool gameOver = false;
    bool win = false;
    spawnRandomNumber();
    spawnRandomNumber();

    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = false;
            else if (event.type == SDL_KEYDOWN)
            {
                handleKey(event, gameOver, win);
            }
        }

        SDL_SetRenderDrawColor(renderer, 250, 248, 239, 255);
        SDL_RenderClear(renderer);
        image.renderer(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        scoreBox.renderer(149, 95, 140, 80);
        bestBox.renderer(410, 95, 140, 80);
        renderScore(renderer, font, score, 219, 138);
        renderScore(renderer, font, best, 481, 138);

        drawBoard(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, font);

        if (gameOver)
        {
            SDL_Color color = {255, 0, 0};
            SDL_Surface* surface = TTF_RenderText_Solid(font, "Game Over! Press R to restart", color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            int textW, textH;
            SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
            SDL_Rect textRect = { (SCREEN_WIDTH - textW) / 2, (SCREEN_HEIGHT - textH) / 2 + 45, textW, textH };
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }

        if (win)
        {
            SDL_Color color = {0, 128, 0};
            SDL_Surface* surface = TTF_RenderText_Solid(font, "You win! Press R to restart", color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            int textW, textH;
            SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
            SDL_Rect textRect = { (SCREEN_WIDTH - textW) / 2, (SCREEN_HEIGHT - textH) / 2 + 45, textW, textH };
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    return 0;
}
