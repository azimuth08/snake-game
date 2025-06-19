#include "../include/game.h"
#include "../include/main.h"
#include "../include/init_sdl.h"
#include "../include/Apple.h"
#include "../include/Player.h"
#include "../include/load_media.h"

bool game_new(struct Game* g)
{
    if ( !init_SDL(g) )
    {
        return false;
    }

    printf("Initialized length of snake : %d\n", g->snake.getLength());

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

    if( g->spriteSheet.getTexture())
    {
        g->spriteSheet.free();
    
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
                    case SDL_SCANCODE_W :
                        g->spriteSheet.render(g, WINDOW_WIDTH / 2.0 , WINDOW_HEIGHT / 2.0, &g->spriteClips[SNAKE_SPRITE_HEAD_UP]);
                        break;

                    case SDL_SCANCODE_A :
                        g->spriteSheet.render(g, WINDOW_WIDTH / 2.0 , WINDOW_HEIGHT / 2.0, &g->spriteClips[SNAKE_SPRITE_HEAD_LEFT]);
                        break;

                    case SDL_SCANCODE_S :
                        g->spriteSheet.render(g, WINDOW_WIDTH / 2.0 , WINDOW_HEIGHT / 2.0, &g->spriteClips[SNAKE_SPRITE_HEAD_DOWN]);
                        break;

                    case SDL_SCANCODE_D :
                        g->spriteSheet.render(g, WINDOW_WIDTH / 2.0 , WINDOW_HEIGHT / 2.0, &g->spriteClips[SNAKE_SPRITE_HEAD_RIGHT]);
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
    

    //g->spriteSheet.render(g, WINDOW_WIDTH / 2.0 , WINDOW_HEIGHT / 2.0, &g->spriteClips[SNAKE_SPRITE_HEAD_UP]);

    SDL_RenderPresent(g->renderer);
}

void run_game(struct Game* g)
{
    SDL_SetRenderDrawColor(g->renderer,128, 110, 255, 255);

    if( !load_media(g))
    {
        printf (" Could not load Media \n");
    }
    
    while ( g->is_running )
    {
        game_events(g);
        game_draw(g);

        SDL_Delay(16);
    }


}