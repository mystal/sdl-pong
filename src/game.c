#include "game.h"

#include <stdbool.h>
#include "SDL.h"

#include "ball.h"
#include "event_handler.h"
#include "player.h"

void game_init()
{
    srandomdev();

    player_init(&player1);
    player_init(&player2);

    ball_init(&ball1);

    screen = SDL_SetVideoMode(GAME_WIDTH, GAME_HEIGHT, GAME_DEPTH, SDL_SWSURFACE);

    bg = SDL_CreateRGBSurface(SDL_SWSURFACE, GAME_WIDTH, GAME_HEIGHT, GAME_DEPTH, 0, 0, 0, 0);
    SDL_FillRect(bg, 0, SDL_MapRGB(bg->format, 0, 0, 0));

    wall = SDL_CreateRGBSurface(SDL_SWSURFACE, GAME_WIDTH, WALL_HEIGHT, GAME_DEPTH, 0, 0, 0, 0);
    SDL_FillRect(wall, 0, SDL_MapRGB(wall->format, 255, 255, 255));

    p = SDL_CreateRGBSurface(SDL_SWSURFACE, PLAYER_WIDTH, PLAYER_HEIGHT, GAME_DEPTH, 0, 0, 0, 0);
    SDL_FillRect(p, 0, SDL_MapRGB(p->format, 255, 255, 255));

    b = SDL_CreateRGBSurface(SDL_SWSURFACE, BALL_SIZE, BALL_SIZE, GAME_DEPTH, 0, 0, 0, 0);
    SDL_FillRect(b, 0, SDL_MapRGB(b->format, 255, 255, 255));

    game_display();
}

bool game_update()
{
    bool quit = false;
    quit = handle_events();
    if (player1.moving != 0)
        player_move(&player1);
    if (player2.moving != 0)
        player_move(&player2);
    ball_move(&ball1);
    return quit;
}

void game_display()
{
    SDL_BlitSurface(bg, NULL, screen, NULL);

    SDL_Rect rect;
    rect.w = GAME_WIDTH;
    rect.h = WALL_HEIGHT;
    rect.x = rect.y = 0;
    SDL_BlitSurface(wall, NULL, screen, &rect);
    rect.y = GAME_HEIGHT - WALL_HEIGHT;
    SDL_BlitSurface(wall, NULL, screen, &rect);

    rect.w = PLAYER_WIDTH;
    rect.h = PLAYER_HEIGHT;
    rect.x = 10;
    rect.y = player1.pos;
    SDL_BlitSurface(p, NULL, screen, &rect);
    rect.x = GAME_WIDTH - PLAYER_WIDTH - 10;
    rect.y = player2.pos;
    SDL_BlitSurface(p, NULL, screen, &rect);

    rect.w = rect.y = BALL_SIZE;
    rect.x = ball1.posX;
    rect.y = ball1.posY;
    SDL_BlitSurface(b, NULL, screen, &rect);

    SDL_Flip(screen);
}

void game_cleanup()
{
    SDL_FreeSurface(bg);
    SDL_FreeSurface(wall);
    SDL_FreeSurface(p);
    SDL_FreeSurface(b);
}
