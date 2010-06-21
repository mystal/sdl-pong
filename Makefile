CC := clang
PLATFORM := OSX

SRCDIR := src/
BUILDDIR := build/

OBJS := $(BUILDDIR)main.o

SDL_INCS := `sdl-config --cflags`
SDL_LIBS := `sdl-config --libs`

INCS := $(SDL_INCS)
LIBS := $(SDL_LIBS)

COMPILE := $(CC) $(INCS) $(LIBS)

.PHONY: all clean

all: ping

clean:
	-rm -rf $(BUILDDIR)

ping: build main.o
	$(COMPILE) -o $(BUILDDIR)ping $(OBJS)

main.o: $(SRCDIR)main.c
	$(COMPILE) -c $(SRCDIR)main.c

build:
	-mkdir $(BUILDDIR)
