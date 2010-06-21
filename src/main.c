#include <stdbool.h>
#include <stdio.h>
#include "SDL.h"

//#include "event_handler.c"

#define FPS 25
#define SKIP_TIME 1000/FPS

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    bool quit = false;

    unsigned int next_game_tick = SDL_GetTicks();
    unsigned int sleep_time = 0;

    while (!quit)
    {
        //update_game();
        //display_game();

        //Check if quit events have come

        next_game_tick += SKIP_TIME;
        sleep_time = next_game_tick - SDL_GetTicks();
        if (sleep_time >= 0)
            SDL_Delay(sleep_time);
        else
        {
            //Shit! We're running behind
        }
    }
}
