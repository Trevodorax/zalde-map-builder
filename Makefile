# Directories
SRCDIR := src
OBJDIR := build
INCDIR := include

# Files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE := bin/index

# Compiler settings
CC := gcc
CFLAGS := -Wall -g -Iinclude
LIBS:= $(shell sdl2-config --cflags --libs) -lSDL2_ttf

# Executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p bin
	$(CC) $(OBJECTS) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build
clean:
	rm -rf build bin
