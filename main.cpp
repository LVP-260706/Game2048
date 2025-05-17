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
    SDL_Rect startButtonRect = {SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT - 180, 400, 100};

    Image scoreBox("Image/score.png", renderer);
    Image bestBox("Image/best.png", renderer);
    Image backGround("Image/background.png", renderer);

    Image gameOver_IMG("Image/gameover.png", renderer);
    Image youWin_IMG("Image/youWin.png", renderer);
    Image restartButton("Image/restart.png", renderer);
    SDL_Rect restartButtonRect = {SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT - 150, 100, 100};
    Image homeButton("Image/home.png", renderer);
    SDL_Rect homeButtonRect = {SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT - 150, 100, 100};

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
                    cerr << "Start Game" << endl;
                    startMenu = false;
                    gameOver = false;
                    win = false;
                    resetGame();
                }
            }
            else if (!startMenu && event.type == SDL_KEYDOWN)
            {
                handleKey(event, gameOver, win);
            }
            else if ((gameOver || win) && event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                if (mouseX >= restartButtonRect.x && mouseX <= restartButtonRect.x + restartButtonRect.w &&
                        mouseY >= restartButtonRect.y && mouseY <= restartButtonRect.y + restartButtonRect.h)
                {
                    cerr << "Restart Game" << endl;
                    resetGame();
                    gameOver = false;
                    win = false;
                }
                if (mouseX >= homeButtonRect.x && mouseX <= homeButtonRect.x + homeButtonRect.w &&
                        mouseY >= homeButtonRect.y && mouseY <= homeButtonRect.y + homeButtonRect.h)
                {
                    cerr << "Menu" << endl;
                    startMenu = true;
                }
            }
        }
        if (startMenu)
        {
            mainBackground.renderer(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            startButton.renderer(startButtonRect.x, startButtonRect.y, startButtonRect.w, startButtonRect.h);
        }
        else
        {
            backGround.renderer(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            scoreBox.renderer(180, 32, 140, 120);
            bestBox.renderer(470, 32, 140, 120);
            renderScore(renderer, font, score, 250, 95);
            renderScore(renderer, font, best, 540, 95);

            drawBoard(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, font);

            if (gameOver || win)
            {
                if (gameOver)
                {
                    gameOver_IMG.renderer(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                    restartButton.renderer(restartButtonRect.x, restartButtonRect.y, restartButtonRect.w, restartButtonRect.h);
                    homeButton.renderer(homeButtonRect.x, homeButtonRect.y, homeButtonRect.w, homeButtonRect.h);
                }
                else if (win)
                {
                    youWin_IMG.renderer(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                    restartButton.renderer(restartButtonRect.x, restartButtonRect.y, restartButtonRect.w, restartButtonRect.h);
                    homeButton.renderer(homeButtonRect.x, homeButtonRect.y, homeButtonRect.w, homeButtonRect.h);
                }
            }
        }
        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    return 0;
}
