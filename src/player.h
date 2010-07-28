#pragma once

#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 100

typedef struct __player {
    int pos;
    unsigned int score;
} player;

void player_init(player *);
