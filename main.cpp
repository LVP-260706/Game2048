#include "Window.h"
#include "Image.h"
using namespace std;
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
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
        image.renderer(100, 50, 600, 400);
        SDL_RenderPresent(renderer);
    }
    return 0;
}
