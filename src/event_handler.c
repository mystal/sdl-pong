#include "event_handler.h"

#include "game.h"



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
                //printKeyInfo(&event.key);
                handle_key();
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

void handle_key()
{
}
