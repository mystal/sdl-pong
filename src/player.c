#include "player.h"

#include "game.h"

void player_init(player *p)
{
    p->pos = GAME_HEIGHT/2 - PLAYER_HEIGHT/2;
    p->moving = 0;
    p->score = 0;
}

void player_move(player *p)
{
    if (p->moving == 1)
    {
        p->pos -= 10;
    }
    else if (p->moving == -1)
    {
        p->pos += 10;
    }
    if (p->pos < TOP_WALL)
        p->pos = TOP_WALL;
    else if ((p->pos + PLAYER_HEIGHT) > BOT_WALL)
        p->pos = BOT_WALL - PLAYER_HEIGHT;
}
