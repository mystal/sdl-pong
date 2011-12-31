set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(pong_SOURCES ball.c event_handler.c game.c main.c player.c)

add_executable(pong ${pong_SOURCES})

target_link_libraries(pong ${SDL_LIBRARY} ${SDLTTF_LIBRARY})
