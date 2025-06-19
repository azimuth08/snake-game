#ifndef LTEXTURE_H_
#define LTEXTURE_H_


#include "main.h"
#include <string>

enum 
{
    SNAKE_SPRITE_HEAD_LEFT,
    SNAKE_SPRITE_HEAD_RIGHT,
    SNAKE_SPRITE_HEAD_UP,
    SNAKE_SPRITE_HEAD_DOWN,
    SNAKE_SPRITE_TAIL_LEFT,
    SNAKE_SPRITE_TAIL_RIGHT,
    SNAKE_SPRITE_TAIL_UP,
    SNAKE_SPRITE_TAIL_DOWN,
    SNAKE_SPRITE_BODY_LR,
    SNAKE_SPRITE_BODY_UD,
    SNAKE_SPRITE_TURN_UL,
    SNAKE_SPRITE_TURN_UR,
    SNAKE_SPRITE_TURN_DL,
    SNAKE_SPRITE_TURN_DR,
    APPLE_SPRTE,
    TOTAL_SPRITES
};

struct Game;

class LTexture
{
    public:
        // contructor
        LTexture() : mTexture(NULL), width(40), height(65) {};
        
        // destructor
        ~LTexture();
        
        // load file from path
        bool loadFromFile(std::string, struct Game* g);

        // free up space
        void free();

        // rendure texture to renderer
        bool render(struct Game* g, float x, float y,  SDL_FRect* clip);

        int getWitdth();
        int getHeight();
        SDL_Texture* getTexture();

    private:
        
        // the actual hardware texture
        SDL_Texture* mTexture;

        int width, height;
};

#endif