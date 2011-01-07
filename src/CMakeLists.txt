set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(ping_SOURCES ball.c event_handler.c game.c main.c player.c)

add_executable(ping ${ping_SOURCES})

target_link_libraries(ping ${SDL_LIBRARY} ${SDLTTF_LIBRARY})
