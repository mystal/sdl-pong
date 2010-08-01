#include "event_handler.h"

#include <stdio.h>
#include "SDL.h"

#include "game.h"
#include "player.h"

typedef struct __key_state {
    SDLKey key;
    unsigned int state : 8;
} key_state;

key_state keys[4];

void handle_key(SDL_KeyboardEvent *);

void event_handler_init()
{
    keys[0].key = SDLK_UP;
    keys[1].key = SDLK_DOWN;
    keys[2].key = SDLK_w;
    keys[3].key = SDLK_s;
    keys[0].state = SDL_RELEASED;
    keys[1].state = SDL_RELEASED;
    keys[2].state = SDL_RELEASED;
    keys[3].state = SDL_RELEASED;
}

bool handle_events()
{
    bool quit = false;
    SDL_Event event;

    //Poll for events
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            //A Keyboard event, pass data to PrintKeyInfo
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                handle_key(&event.key);
                break;

            //SDL_QUIT event (window close)
            case SDL_QUIT:
                quit = true;
                break;

            default:
                break;
        }
    }
    return quit;
}

void handle_key(SDL_KeyboardEvent *key)
{
    if (key->keysym.sym == SDLK_UP)
        keys[0].state = key->state;
    else if (key->keysym.sym == SDLK_DOWN)
        keys[1].state = key->state;
    if (key->keysym.sym == SDLK_w)
        keys[2].state = key->state;
    else if (key->keysym.sym == SDLK_s)
        keys[3].state = key->state;

    if (keys[0].state == SDL_PRESSED && keys[1].state == SDL_PRESSED)
        player1.moving = 0;
    else if (keys[0].state == SDL_PRESSED)
        player1.moving = 1;
    else if (keys[1].state == SDL_PRESSED)
        player1.moving = -1;
    else
        player1.moving = 0;

    if (keys[2].state == SDL_PRESSED && keys[3].state == SDL_PRESSED)
        player2.moving = 0;
    else if (keys[2].state == SDL_PRESSED)
        player2.moving = 1;
    else if (keys[3].state == SDL_PRESSED)
        player2.moving = -1;
    else
        player2.moving = 0;
}
