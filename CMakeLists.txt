# cmake minimum version
cmake_minimum_required(VERSION 2.6)

# Project name
project(pong C)

# Include modules for finding SDL
include(FindSDL)
include(FindSDL_ttf)

# Check for SDL
if(SDL_FOUND)
    include_directories(${SDL_INCLUDE_DIR})
else(SDL_FOUND)
    message("Could not find SDL!")
endif(SDL_FOUND)
# Check for SDL_ttf
# Currently requires fix in FindSDL_ttf, need to add include/SDL under
# the PATH SUFFIXES for the include dir
if(SDLTTF_FOUND)
    include_directories(${SDLTTF_INCLUDE_DIR})
else(SDLTTF_FOUND)
    message("Could not find SDL_ttf!")
endif(SDLTTF_FOUND)

add_definitions(--std=gnu99)

add_subdirectory(src)
