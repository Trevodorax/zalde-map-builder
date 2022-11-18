# EXE does not mean ".exe" file extension, but the executable file
# @<command> means that the command will not be printed to the terminal
# $@ means the target name


# VARIABLES

# Compiler settings
CC := gcc
CFLAGS := -Wall -g

# Executable
EXE := bin/index

# Main object & source file
MAINO := build/main.o
MAINC := src/main.c

# Utils object & source file
UTILSO := build/utils.o
UTILSC := lib/utils.c

# Objects string
OBJS := $(MAINO) $(UTILSO)


# TARGETS

# Build executable
$(EXE): $(OBJS)
	@mkdir -p bin
	$(CC) $(OBJS) -o $@

# Build main object
$(MAINO): $(MAINC)
	@mkdir -p build
	$(CC) $(CFLAGS) -c $(MAINC) -o $@

# Build utils object
$(UTILSO): $(UTILSC)
	@mkdir -p build
	$(CC) $(CFLAGS) -c $(UTILSC) -o $@

# Clean build
clean:
	rm -rf build bin
