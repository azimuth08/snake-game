#include "../include/game.h"
#include "../include/main.h"
#include "../include/init_sdl.h"


bool game_new(struct Game* g)
{
    if ( !init_SDL(g) )
    {
        return false;
    }

    g->is_running = true;

    return true;
}

void close(struct Game* g)
{
    if ( g->window )
    {
        SDL_DestroyWindow(g->window);
        g->window = NULL;
    }

    if( g->renderer )
    {
        SDL_DestroyRenderer(g->renderer);
        g->renderer = NULL;
    }

    SDL_Quit();
}

void game_events(struct Game* g)
{
    while ( SDL_PollEvent(&g->event) )
    {
        switch ( g->event.type )
        {
            case SDL_EVENT_QUIT:
                g->is_running = false;
                break;
            
            case SDL_EVENT_KEY_DOWN:
                switch(g->event.key.scancode)
                {
                    case SDL_SCANCODE_ESCAPE :
                        g->is_running = false;
                        break;
                    
                    default :
                        break;

                }
            default:
                break;

        }

    }
}

void game_draw(struct Game* g)
{
    SDL_RenderClear(g->renderer);
    SDL_RenderPresent(g->renderer);
}

void run_game(struct Game* g)
{
    SDL_SetRenderDrawColor(g->renderer,128, 250, 100, 255);
    while ( g->is_running )
    {
        game_events(g);
        game_draw(g);

        SDL_Delay(16);
    }


}