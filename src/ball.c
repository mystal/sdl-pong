#include "ball.h"

#include "game.h"

int distance(int a, int b);

void ball_init(ball *b)
{
    //b->posX = GAME_WIDTH/2;
    //b->posY = GAME_HEIGHT/2;
    b->posX = 100;
    b->posY = 100;
}

bool hit_player(ball *b, player *p)
{
}

bool hit_wall(ball *b)
{
}

bool scored(ball *b)
{
}
