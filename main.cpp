#include "Window.h"
#include "Image.h"
#include "Grid.h"
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
        drawBoard(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, font);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}
