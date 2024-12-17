# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = input

# Source file
SRC = input.c

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean target to remove the executable
clean:
	rm -f $(TARGET)