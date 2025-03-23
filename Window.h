#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Window
{
public:
    Window(const char* title, int width, int height);
    ~Window();
    SDL_Renderer* getRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
#endif // WINDOW_H
