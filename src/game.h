#pragma once

#include <stdbool.h>
#include "SDL.h"

#include "ball.h"
#include "player.h"

#define GAME_WIDTH 640
#define GAME_HEIGHT 480

#define GAME_DEPTH 32

#define WALL_HEIGHT 10
#define TOP_WALL (WALL_HEIGHT)
#define BOT_WALL (GAME_HEIGHT - WALL_HEIGHT)

#define PLAYER1_POSX (PLAYER_POSX)
#define PLAYER2_POSX (GAME_WIDTH - PLAYER_WIDTH - PLAYER_POSX)

#define SCORE_WIDTH 15
#define SCORE_HEIGHT 20

player player1;
player player2;

ball ball1;

SDL_Surface *screen;

SDL_Surface *bg;
SDL_Surface *wall;
SDL_Surface *p;
SDL_Surface *b;
SDL_Surface *score1;
SDL_Surface *score2;

SDL_Surface *score_text[10];

void game_init();

bool game_update();

void game_display();

void game_cleanup();
