# Makefile for Arduino Projects

# =====================
#       Variables
# =====================

# Compiler and tools
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# MCU and Frequency
MCU = atmega328p
F_CPU = 16000000UL

# Programmer configuration
PROGRAMMER = arduino
BAUD = 115200
PORT = /dev/tty.usbserial-110

# Source and build directories
SRC_DIR = .                    # Using current directory for source files
BUILD_DIR = build

# Source files (all .c files in SRC_DIR)
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files (place them in BUILD_DIR)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Output files
ELF = $(BUILD_DIR)/knight.elf
HEX = $(BUILD_DIR)/knight.hex

# Compiler flags
CFLAGS = -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)

# =====================
#       Targets
# =====================

.PHONY: all build flash clean

# Default target
all: build

# Build target: Compile all source files and create HEX
build: $(HEX)

# Link object files to create ELF
$(ELF): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Convert ELF to HEX
$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

# Compile .c files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Flash target: Upload HEX to Arduino
flash: $(HEX)
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -b $(BAUD) -D -U flash:w:$<:i

# Clean target: Remove build files
clean:
	rm -rf $(BUILD_DIR)