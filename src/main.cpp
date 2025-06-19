#include "../include/main.h"
#include "../include/game.h"

bool game_new(struct Game* g);
void run_game(struct Game* g);
void close(struct Game* g);

int main (int argc, char* argv[])
{
    bool exit_status = 1;

    struct Game game = {NULL};

    if ( game_new(&game) )
    {

        run_game(&game);
        exit_status = 0;
    }

    close(&game);
    return exit_status;
}



