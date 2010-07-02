#pragma once

typedef struct __player {
    int pos;
    unsigned int score;
} player;

void player_init(player *);
