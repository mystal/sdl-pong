PLATFORM := OSX

CC := clang

SRCDIR := src
BUILDDIR := build

OBJS := main.o game.o player.o ball.o event_handler.o 

SDL_INCS := `sdl-config --cflags`
SDL_LIBS := `sdl-config --libs` -lSDL_ttf

INCS := $(SDL_INCS)
LIBS := -lm $(SDL_LIBS)

.PHONY: all clean

all: $(BUILDDIR)/ping

clean:
	-rm -rf $(BUILDDIR)

$(BUILDDIR)/ping: $(addprefix $(BUILDDIR)/, $(OBJS))
	$(CC) $(LIBS) -g -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(INCS) -g -c -o $@ $<

build:
	mkdir $(BUILDDIR)
