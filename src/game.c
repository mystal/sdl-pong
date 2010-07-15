#include "game.h"

#include <stdbool.h>

#include "ball.h"
#include "event_handler.h"
#include "player.h"

void game_init()
{
    player_init(&player1);
    player_init(&player2);

    ball_init(&ball1);

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
}

bool game_update()
{
    bool quit = false;
    quit = handle_events();
    return quit;
}

void game_display()
{
}

void game_cleanup()
{
}
