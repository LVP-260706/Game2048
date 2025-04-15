#include "Window.h"
using namespace std;

Window::Window(const char* title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << SDL_GetError() << endl;
        exit(-1);
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        cerr << IMG_GetError() << endl;
        SDL_Quit();
        exit(-1);
    }
    if (TTF_Init() == -1)
    {
        cerr << TTF_GetError() << endl;
        IMG_Quit();
        SDL_Quit();
        exit(-1);
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        cerr << SDL_GetError() << endl;
        SDL_Quit();
        exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        cerr << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        exit(-1);
    }
}
Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
SDL_Renderer* Window::getRenderer()
{
    return renderer;
}
