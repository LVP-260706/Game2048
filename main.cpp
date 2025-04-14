#include "Window.h"
#include "Image.h"
#include "Grid.h"
#include "Logic.h"
using namespace std;
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

int main(int argc, char* argv[])
{
    if (TTF_Init() == -1)
    {
        cerr << TTF_GetError() << endl;
        return -1;
    }

    Window window("Game 2048", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.getRenderer();
    Image image("Image/2048_mainImage.png", renderer);

    TTF_Font* font = TTF_OpenFont("Image/Roboto-Regular.ttf", 25);
    if (!font)
    {
        cerr << TTF_GetError() << endl;
        SDL_DestroyRenderer(renderer);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    bool running = true;
    bool gameOver = false;
    spawnRandomNumber();
    spawnRandomNumber();

    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = false;
            else if (event.type == SDL_KEYDOWN && !gameOver)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        moveLeft();
                        break;
                    case SDLK_RIGHT:
                        moveRight();
                        break;
                    case SDLK_UP:
                        moveUp();
                        break;
                    case SDLK_DOWN:
                        moveDown();
                        break;
                }
                if (!canMove()) gameOver = true;
            }
            else if (event.type == SDL_KEYDOWN && gameOver)
            {
                if (event.key.keysym.sym == SDLK_r)
                {
                    memset(board, 0, sizeof(board));
                    spawnRandomNumber();
                    spawnRandomNumber();
                    gameOver = false;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 250, 248, 239, 255);
        SDL_RenderClear(renderer);
        image.renderer(0, 0, 800, 600);
        drawBoard(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, font);

        if (gameOver)
        {
            SDL_Color color = {255, 0, 0};
            SDL_Surface* surface = TTF_RenderText_Solid(font, "Game Over! Press R to restart", color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            int textW, textH;
            SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
            SDL_Rect textRect = { (SCREEN_WIDTH - textW) / 2, SCREEN_HEIGHT - 80, textW, textH };
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }

        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}
