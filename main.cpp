#include "Window.h"
#include "Image.h"
#include "Grid.h"
using namespace std;
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

int main(int argc, char* argv[])
{
    Window window("Game 2048", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.getRenderer();
    Image image("Image/2048_mainImage.png", renderer);
    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) running = false;
        }
        SDL_SetRenderDrawColor(renderer, 250, 248, 239, 255);
        SDL_RenderClear(renderer);
        image.renderer(0, 0, 800, 600);
        drawBoard(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
        SDL_RenderPresent(renderer);
    }
    return 0;
}
