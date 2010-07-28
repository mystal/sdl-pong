#pragma once

#include <stdbool.h>

#include "player.h"

#define BALL_SIZE 20

typedef struct __ball {
    int posX;
    int posY;
} ball;

void ball_init(ball *);

bool hit_player(ball *, player *);

bool hit_wall(ball *);

bool scored(ball *);
