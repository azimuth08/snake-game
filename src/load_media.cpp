#include "../include/load_media.h"
#include "../include/game.h"

bool load_media(struct Game* g)
{
    // configure sprite sheet
    g->spriteSheet.loadFromFile("../resources/sprite/snake-graphics.png", g);
    if ( !g->spriteSheet.getTexture() )
    {
        printf("Could not load sprite sheet\n");
        return false;
    }

    // set each sprite's dimension from sprite sheet
    g->spriteClips[SNAKE_SPRITE_HEAD_UP].x = 192;
    g->spriteClips[SNAKE_SPRITE_HEAD_UP].y = 1;
    g->spriteClips[SNAKE_SPRITE_HEAD_UP].w = 64;
    g->spriteClips[SNAKE_SPRITE_HEAD_UP].h = 64;

    g->spriteClips[SNAKE_SPRITE_HEAD_RIGHT].x = 256;
    g->spriteClips[SNAKE_SPRITE_HEAD_RIGHT].y = 63;
    g->spriteClips[SNAKE_SPRITE_HEAD_RIGHT].w = 64;
    g->spriteClips[SNAKE_SPRITE_HEAD_RIGHT].h = 64;

    g->spriteClips[SNAKE_SPRITE_HEAD_LEFT].x = 193;
    g->spriteClips[SNAKE_SPRITE_HEAD_LEFT].y = 64;
    g->spriteClips[SNAKE_SPRITE_HEAD_LEFT].w = 64;
    g->spriteClips[SNAKE_SPRITE_HEAD_LEFT].h = 64;

    g->spriteClips[SNAKE_SPRITE_HEAD_DOWN].x = 256;
    g->spriteClips[SNAKE_SPRITE_HEAD_DOWN].y = 63;
    g->spriteClips[SNAKE_SPRITE_HEAD_DOWN].w = 64;
    g->spriteClips[SNAKE_SPRITE_HEAD_DOWN].h = 64;

    return true;
}