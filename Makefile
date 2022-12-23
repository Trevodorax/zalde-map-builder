# EXE does not mean ".exe" file extension, but the executable file
# @<command> means that the command will not be printed to the terminal
# $@ means the target name


# VARIABLES

# Compiler settings
CC := gcc
CFLAGS := -Wall -g -Iinclude
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

# managing texture picking
TEXTUREPICKERO := build/texturePicker.o	
TEXTUREPICKERC := src/texturePicker.c

# managing the texture category
TEXTUREPICKERNAVIGATIONO := build/texturePickerNavigation.o	
TEXTUREPICKERNAVIGATIONC := src/texturePickerNavigation.c

# handling events
EVENTSO := build/events.o
EVENTSC := src/events.c

# click listeners
CLICKLISTENERSO := build/clickListeners.o
CLICKLISTENERSC := src/clickListeners.c

# Button handling
BUTTONO := build/button.o
BUTTONC := src/button.c

# Objects string
OBJS := $(MAINO) $(UTILSO) $(SDLUTILSO) $(WINDOWMANAGERO) $(BUTTONO) $(EVENTSO) $(TEXTUREPICKERO) $(TEXTUREPICKERNAVIGATIONO) $(CLICKLISTENERSO)

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

# Build window manager object
$(WINDOWMANAGERO): $(WINDOWMANAGERC)
	@mkdir -p build
	$(CC) -c $(WINDOWMANAGERC) $(CFLAGS) -o $@

# Build texture picker object
$(TEXTUREPICKERO): $(TEXTUREPICKERC)
	@mkdir -p build
	$(CC) -c $(TEXTUREPICKERC) $(CFLAGS) -o $@

# Build texture picker navigation object
$(TEXTUREPICKERNAVIGATIONO): $(TEXTUREPICKERNAVIGATIONC)
	@mkdir -p build
	$(CC) -c $(TEXTUREPICKERNAVIGATIONC) $(CFLAGS) -o $@

# Build events object
$(EVENTSO): $(EVENTSC)
	@mkdir -p build
	$(CC) -c $(EVENTSC) $(CFLAGS) -o $@

# Build click listeners object
$(CLICKLISTENERSO): $(CLICKLISTENERSC)
	@mkdir -p build
	$(CC) -c $(CLICKLISTENERSC) $(CFLAGS) -o $@

# Build button object
$(BUTTONO): $(BUTTONC)
	@mkdir -p build
	$(CC) -c $(BUTTONC) $(CFLAGS) -o $@

# Clean build
clean:
	rm -rf build bin
