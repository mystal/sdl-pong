#include "ball.h"

#include <math.h>

#include "game.h"

int distance(int a, int b);

void ball_init(ball *b)
{
    b->posX = GAME_WIDTH/2 - BALL_SIZE/2;
    b->posY = GAME_HEIGHT/2 - BALL_SIZE/2;
    //double r = (double)random()/RAND_MAX;
    //fprintf(stderr, "random number: %f\n", r);
    b->angle = 2*M_PI*((double)random()/RAND_MAX);
}

void ball_move(ball *b)
{
    b->posX += round(BALL_SPEED*cos(b->angle));
    b->posY += round(BALL_SPEED*sin(b->angle));
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
