#include <SDL3/SDL.h>
//#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

//GLOBALS
#define WINDOW_TITLE "Snake game"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define SDL_FLAGS SDL_INIT_VIDEO

struct Game
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    bool is_running;
};

bool init_SDL(struct Game* g);
bool game_new(struct Game* g);
void close(struct Game* g);
void game_events(struct Game* g);
void game_draw(struct Game* g);
void run_game(struct Game* g);


// initialize SDL 
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
    SDL_SetRenderDrawColor(g->renderer,128, 55, 0, 255);
    while ( g->is_running )
    {
        game_events(g);
        game_draw(g);

        SDL_Delay(16);
    }


}

int main (int argc, char* argv[])
{
    bool exit_status = 1;

    struct Game game = {0};

    if ( game_new(&game) )
    {

        run_game(&game);
        exit_status = 0;
    }

    close(&game);
    return exit_status;
}



