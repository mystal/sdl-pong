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
#define PLAYER1_LEFT (PLAYER1_POSX)
#define PLAYER1_RIGHT (PLAYER1_POSX + PLAYER_WIDTH)
#define PLAYER1_TOP (player1.pos)
#define PLAYER1_BOT (player1.pos + PLAYER_HEIGHT)
#define PLAYER2_POSX (GAME_WIDTH - PLAYER_WIDTH - PLAYER_POSX)
#define PLAYER2_LEFT (PLAYER2_POSX)
#define PLAYER2_RIGHT (PLAYER2_POSX + PLAYER_WIDTH)
#define PLAYER2_TOP (player2.pos)
#define PLAYER2_BOT (player2.pos + PLAYER_HEIGHT)

#define BALL_LEFT (b->posX)
#define BALL_RIGHT (b->posX + BALL_SIZE)
#define BALL_TOP (b->posY)
#define BALL_BOT (b->posY + BALL_SIZE)

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
