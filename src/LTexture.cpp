#include "../include/LTexture.h"
#include "../include/game.h"
LTexture::~LTexture()
{

}

void LTexture::free()
{
    if ( mTexture )
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
    }
}

bool LTexture::loadFromFile(std::string path, struct Game* g)
{
    mTexture = IMG_LoadTexture(g->renderer, path.c_str());
    if( !mTexture )
    {
        printf("Could not load texture from file %s. SDL ERROR : %s\n", path.c_str(), SDL_GetError());
        return false;
    }
    return true;
}

bool LTexture::render(struct Game* g, float x, float y,  SDL_FRect* clip)
{
    SDL_FRect renderBox = {x, y, width, height};

    if ( clip )
    {
        renderBox.w = clip->w;
        renderBox.h = clip->h;
        printf("Made it %f \n", clip->x);
    }
    
    SDL_RenderTexture(g->renderer,mTexture,clip,&renderBox);
    return true;
}

int LTexture::getWitdth()
{
    return width;
}

int LTexture::getHeight()
{
    return height;
}

SDL_Texture* LTexture::getTexture()
{
    return mTexture;
}