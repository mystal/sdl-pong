#include <stdbool.h>
#include <stdio.h>
#include "SDL.h"

#include "game.h"

#define FPS 25
#define SKIP_TIME 1000/FPS

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    game_init();

    bool quit = false;

    int next_game_tick = SDL_GetTicks();
    int sleep_time = 0;

    while (!quit)
    {
        quit = game_update();
        game_display();

        next_game_tick += SKIP_TIME;
        sleep_time = next_game_tick - SDL_GetTicks();
        if (sleep_time >= 0)
            SDL_Delay(sleep_time);
        else
        {
            //Shit! We're running behind
            fprintf(stderr, "Lag...\n");
        }
    }

    game_cleanup();

    SDL_Quit();

    return 0;
}
