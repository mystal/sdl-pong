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

player player1;
player player2;

ball ball1;

SDL_Surface *screen;

SDL_Surface *bg;
SDL_Surface *wall;
SDL_Surface *p;
SDL_Surface *b;

void game_init();

bool game_update();

void game_display();

void game_cleanup();
