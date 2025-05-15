#include "Window.h"
#include "Image.h"
#include "Grid.h"
#include "Logic.h"

#include <string>
using namespace std;
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

int main(int argc, char* argv[])
{
    Window window("Game 2048", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.getRenderer();

    Image mainBackground("Image/main.png", renderer);
    Image startButton("Image/start.png", renderer);
    SDL_Rect startButtonRect = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT - 180, 200, 80};

    Image scoreBox("Image/score.png", renderer);
    Image bestBox("Image/best.png", renderer);
    Image backGround("Image/background.png", renderer);

    TTF_Font* font = TTF_OpenFont("Image/Roboto-Regular.ttf", 25);
    if (!font)
    {
        cerr << TTF_GetError() << endl;
        return -1;
    }

    bool running = true;
    bool gameOver = false;
    bool win = false;
    bool startMenu = true;

    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = false;
            if (startMenu && event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                if (mouseX >= startButtonRect.x && mouseX <= startButtonRect.x + startButtonRect.w &&
                        mouseY >= startButtonRect.y && mouseY <= startButtonRect.y + startButtonRect.h)
                    {
                        startMenu = false;
                        spawnRandomNumber();
                        spawnRandomNumber();
                    }
            }
            else if (!startMenu && event.type == SDL_KEYDOWN)
            {
                handleKey(event, gameOver, win);
            }
        }
        if (startMenu)
        {
            mainBackground.renderer(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            startButton.renderer(startButtonRect.x, startButtonRect.y, startButtonRect.w, startButtonRect.h);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 220, 218, 209, 255);
            SDL_RenderClear(renderer);
            backGround.renderer(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            scoreBox.renderer(180, 32, 140, 120);
            bestBox.renderer(470, 32, 140, 120);
            renderScore(renderer, font, score, 250, 95);
            renderScore(renderer, font, best, 540, 95);

            drawBoard(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, font);

            if (gameOver || win)
            {
                SDL_Surface* surface;
                if (gameOver)
                {
                    SDL_Color color = {255, 0, 0};
                    surface = TTF_RenderText_Solid(font, "Game Over! Press R to restart", color);
                }
                else if (win)
                {
                    SDL_Color color = {0, 128, 0};
                    surface = TTF_RenderText_Solid(font, "You win! Press R to restart", color);
                }
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                int textW, textH;
                SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
                SDL_Rect textRect = { (SCREEN_WIDTH - textW) / 2, (SCREEN_HEIGHT - textH) / 2 + 45, textW, textH };
                SDL_RenderCopy(renderer, texture, NULL, &textRect);
                SDL_FreeSurface(surface);
                SDL_DestroyTexture(texture);
            }
        }
        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    return 0;
}
