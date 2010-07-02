#pragma once

#include "SDL.h"

#include "ball.h"
#include "player.h"

#define GAME_WIDTH 640
#define GAME_HEIGHT 480

player player1;
player player2;

ball ball1;

void game_init();

void game_update();

void game_display();
