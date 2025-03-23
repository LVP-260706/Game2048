#include "Image.h"
using namespace std;

Image::Image(const char* filename, SDL_Renderer* imageRenderer) : imageRenderer(imageRenderer)
{
    SDL_Surface* imageSurface = IMG_Load(filename);
    if (!imageSurface)
    {
        cerr << IMG_GetError() << endl;
        exit(-1);
    }
    texture = SDL_CreateTextureFromSurface(imageRenderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    if (!texture)
    {
        cerr << SDL_GetError() << endl;
        exit(-1);
    }
}
Image::~Image()
{
    SDL_DestroyTexture(texture);
}
void Image::renderer(int x, int y, int width, int height)
{
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopy(imageRenderer, texture, NULL, &dstRect);
}
