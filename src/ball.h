#pragma once

#include <stdbool.h>

#include "player.h"

#define BALL_SIZE 20
#define BALL_SPEED 10

typedef struct __ball {
    int posX;
    int posY;
    double angle;
} ball;

void ball_init(ball *);

void ball_move(ball *);

unsigned int ball_scored(ball *);
