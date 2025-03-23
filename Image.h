#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Image
{
public:
    Image(const char* filename, SDL_Renderer* renderer);
    ~Image();
    void renderer(int x, int y, int width, int height);
private:
    SDL_Texture* texture;
    SDL_Renderer* imageRenderer;
};
#endif // IMAGE_H
