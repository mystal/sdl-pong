#pragma once

#include <stdbool.h>
#include "SDL.h"

#include "ball.h"
#include "player.h"

#define GAME_WIDTH 640
#define GAME_HEIGHT 480

player player1;
player player2;

ball ball1;

SDL_Surface *screen;

void game_init();

bool game_update();

void game_display();

void game_cleanup();
