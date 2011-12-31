#include "ball.h"

#include <math.h>

#include "game.h"
#include "player.h"

void ball_init(ball *b)
{
    b->posX = GAME_WIDTH/2 - BALL_SIZE/2;
    b->posY = GAME_HEIGHT/2 - BALL_SIZE/2;
    b->angle = 2*M_PI*((double)random()/RAND_MAX);
    while ((b->angle > M_PI/3.0 && b->angle < M_PI*2.0/3.0) ||
           (b->angle > M_PI*4.0/3.0 && b->angle < M_PI*5.0/3.0) ||
           (b->angle < M_PI/9.0 && b->angle > M_PI*17.0/9.0) ||
           (b->angle < M_PI*10.0/9.0 && b->angle > M_PI*8.0/9.0))
        b->angle = 2*M_PI*((double)random()/RAND_MAX);
}

void ball_move(ball *b)
{
    b->posX += round(BALL_SPEED*cos(b->angle));
    b->posY += round(BALL_SPEED*sin(b->angle));

    if (BALL_TOP <= TOP_WALL) //Check hit top wall
    {
        b->posY = (TOP_WALL - b->posY) + TOP_WALL;
        //flip angle across horizontal
        b->angle = 2*M_PI - b->angle;
    }
    else if (BALL_BOT >= BOT_WALL) //Check hit bottom wall
    {
        b->posY = BOT_WALL - (b->posY + BALL_SIZE - BOT_WALL) - BALL_SIZE;
        //flip angle across horizontal
        b->angle = 2*M_PI - b->angle;
    }

    if (BALL_LEFT <= PLAYER1_RIGHT && BALL_TOP >= PLAYER1_TOP &&
        BALL_BOT <= PLAYER1_BOT) //Check hit player1
    {
        b->posX = (PLAYER1_POSX + PLAYER_WIDTH - b->posX) + PLAYER1_POSX + PLAYER_WIDTH;
        //TODO flip angle across vertical
        b->angle = (b->angle > M_PI) ? (2*M_PI - b->angle) + M_PI : M_PI - b->angle;
    }
    else if (BALL_RIGHT >= PLAYER2_POSX && BALL_TOP >= PLAYER2_TOP &&
        BALL_BOT <= PLAYER2_BOT) //Check hit player2
    {
        b->posX = PLAYER2_POSX - (b->posX + BALL_SIZE - PLAYER2_POSX) - BALL_SIZE;
        //TODO flip angle across vertical
        b->angle = (b->angle > M_PI) ? (2*M_PI - b->angle) + M_PI : M_PI - b->angle;
    }
}

unsigned int ball_scored(ball *b)
{
    if (b->posX < -10) //Player 2 scored
        return 2;
    else if (b->posX > GAME_WIDTH - 10) //Player 1 scored
        return 1;
    return 0;
}
