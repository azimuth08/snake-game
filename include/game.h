#ifndef GAME_H_
#define GAME_H_

#include "main.h"

struct Game
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Renderer* background;
    SDL_Event event;
    bool is_running;
};


void game_events(struct Game* g);
void game_draw(struct Game* g);

#endif