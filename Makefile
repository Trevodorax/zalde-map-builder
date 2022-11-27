# EXE does not mean ".exe" file extension, but the executable file
# @<command> means that the command will not be printed to the terminal
# $@ means the target name


# VARIABLES

# Compiler settings
CC := gcc
CFLAGS := -Wall -g
LIBS:= $(shell sdl2-config --cflags --libs)

# Executable
EXE := bin/index

# Main object & source file
MAINO := build/main.o
MAINC := src/main.c

# General utilities file
UTILSO := build/utils.o
UTILSC := src/utils.c

# General utilities for SDL2
SDLUTILSO := build/SDLUtils.o
SDLUTILSC := src/SDLUtils.c

# Handling 2 windows and the communication between them
WINDOWMANAGERO := build/windowManager.o
WINDOWMANAGERC := src/windowManager.c

# Objects string
OBJS := $(MAINO) $(UTILSO) $(SDLUTILSO) $(WINDOWMANAGERO)

# Build executable
$(EXE): $(OBJS)
	@mkdir -p bin
	$(CC) $(OBJS) $(LIBS) -o $@

# Build main object
$(MAINO): $(MAINC)
	@mkdir -p build
	$(CC) -c $(MAINC) $(CFLAGS) -o $@ 

# Build utils object
$(UTILSO): $(UTILSC)
	@mkdir -p build
	$(CC) -c $(UTILSC) $(CFLAGS)  -o $@

# Build SDL utils object
$(SDLUTILSO): $(SDLUTILSC)
	@mkdir -p build
	$(CC) -c $(SDLUTILSC) $(CFLAGS) -o $@

# Build SDL utils object
$(WINDOWMANAGERO): $(WINDOWMANAGERC)
	@mkdir -p build
	$(CC) -c $(WINDOWMANAGERC) $(CFLAGS) -o $@

# Clean build
clean:
	rm -rf build bin
