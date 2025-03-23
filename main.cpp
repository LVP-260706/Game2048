#include "Window.h"
#include "Image.h"
using namespace std;
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

void drawGrid(SDL_Renderer* renderer, int gridSize, int cellSize)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i <= gridSize; i++)
    {
        SDL_RenderDrawLine(renderer, 0, i * cellSize, cellSize * gridSize, i * cellSize);
        SDL_RenderDrawLine(renderer, i * cellSize, 0, i * cellSize, gridSize * cellSize);
    }
}

int main(int argc, char* argv[])
{
    Window window("Game 2048", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.getRenderer();
    Image image("2048_mainImage.png", renderer);
    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = false;
        }
        SDL_RenderClear(renderer);
        image.renderer(0, 0, 800, 600);
        drawGrid(renderer, 4, 100);
        SDL_RenderPresent(renderer);

    }
    return 0;
}
