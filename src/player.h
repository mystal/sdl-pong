#pragma once

#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 100
#define PLAYER_SPEED 10

typedef struct __player {
    int pos;
    int moving;
    unsigned int score;
} player;

void player_init(player *);

void player_move(player *);
