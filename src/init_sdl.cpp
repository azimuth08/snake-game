#include "../include/init_sdl.h"

bool init_SDL(struct Game* g)
{
    if ( !SDL_Init(SDL_FLAGS) )
    {
        printf("Could not initialize SDL. SDL ERROR : %s\n", SDL_GetError());
        return false;
    }

    g->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if ( !g->window )
    {
        printf("Could not initialize SDL Winodw. SDL ERROR : %s\n", SDL_GetError());
        return false;
    }

        
    g->renderer = SDL_CreateRenderer(g->window, NULL);
    if ( !g->renderer )
    {
        printf("Could not initialize SDL Renderer. SDL ERROR : %s\n", SDL_GetError());
        return false;
    }
        

    return true;
}