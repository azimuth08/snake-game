#ifndef GAME_H_
#define GAME_H_

#include "main.h"
#include "Entity.h"
#include "Player.h"
#include "LTexture.h"

struct Game
{
    // windows/setting
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Renderer* background;
    //struct Position map[15][17];
    
    // enities
    LTexture spriteSheet;
    SDL_FRect spriteClips[TOTAL_SPRITES];
    Player snake;
    struct Color playerColor;
    struct Position playerSpawn;
    

    // game loop
    SDL_Event event;
    bool is_running;
};


void game_events(struct Game* g);
void game_draw(struct Game* g);

#endif