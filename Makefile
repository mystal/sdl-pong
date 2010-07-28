PLATFORM := OSX

CC := clang

SRCDIR := src/
BUILDDIR := build/

OBJS := $(BUILDDIR)main.o $(BUILDDIR)game.o $(BUILDDIR)player.o $(BUILDDIR)ball.o $(BUILDDIR)event_handler.o 

SDL_INCS := `sdl-config --cflags`
SDL_LIBS := `sdl-config --libs`

INCS := $(SDL_INCS)
LIBS := $(SDL_LIBS)

#COMPILE := $(CC) $(INCS) $(LIBS)

.PHONY: all clean

all: ping

clean:
	-rm -rf $(BUILDDIR)

ping: main.o game.o player.o ball.o event_handler.o
	$(CC) $(LIBS) -o $(BUILDDIR)ping $(OBJS)

main.o: build $(SRCDIR)main.c
	$(CC) $(INCS) -c -o $(BUILDDIR)main.o $(SRCDIR)main.c

game.o: build $(SRCDIR)game.c
	$(CC) $(INCS) -c -o $(BUILDDIR)game.o $(SRCDIR)game.c

player.o: build $(SRCDIR)player.c
	$(CC) $(INCS) -c -o $(BUILDDIR)player.o $(SRCDIR)player.c

ball.o: build $(SRCDIR)ball.c
	$(CC) $(INCS) -c -o $(BUILDDIR)ball.o $(SRCDIR)ball.c

event_handler.o: build $(SRCDIR)event_handler.c
	$(CC) $(INCS) -c -o $(BUILDDIR)event_handler.o $(SRCDIR)event_handler.c

build:
	-mkdir $(BUILDDIR)
