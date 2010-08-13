#include "ball.h"

#include <math.h>

#include "game.h"

int distance(int a, int b);

void ball_init(ball *b)
{
    b->posX = GAME_WIDTH/2 - BALL_SIZE/2;
    b->posY = GAME_HEIGHT/2 - BALL_SIZE/2;
    b->angle = 2*M_PI*((double)random()/RAND_MAX);
    while ((b->angle > M_PI/4.0 && b->angle < M_PI*3.0/4.0) ||
           (b->angle > M_PI*5.0/4.0 && b->angle < M_PI*7.0/4.0))
        b->angle = 2*M_PI*((double)random()/RAND_MAX);
}

void ball_move(ball *b)
{
    b->posX += round(BALL_SPEED*cos(b->angle));
    b->posY += round(BALL_SPEED*sin(b->angle));

    if (b->posY <= TOP_WALL) //Check hit top wall
    {
        b->posY = (TOP_WALL - b->posY) + TOP_WALL;
        //flip angle across horizontal
        b->angle = 2*M_PI - b->angle;
    }
    else if ((b->posY + BALL_SIZE) >= BOT_WALL) //Check hit bottom wall
    {
        b->posY = BOT_WALL - (b->posY + BALL_SIZE - BOT_WALL) - BALL_SIZE;
        //flip angle across horizontal
        b->angle = 2*M_PI - b->angle;
    }
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
