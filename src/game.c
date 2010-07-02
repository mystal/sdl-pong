#include "game.h"

#include "ball.h"
#include "event_handler.h"
#include "player.h"

void game_init()
{
    player_init(&player1);
    player_init(&player2);

    ball_init(&ball1);
}

void game_update()
{
}

void game_display()
{
}
