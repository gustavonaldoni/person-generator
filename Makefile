EXECUTABLE_NAME = personGenerator.out

SOURCE_DIR = src
SOURCE_FILE = $(SOURCE_DIR)/main.c
LIB_FILES = $(wildcard lib/*.c)

BUILD_DIR = build

CC = cc
RAYLIB_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
CFLAGS = -Wall -Werror

ALL_FLAGS = $(RAYLIB_FLAGS) $(CFLAGS)

all:
	$(CC) $(SOURCE_FILE) -o $(BUILD_DIR)/$(EXECUTABLE_NAME) $(LIB_FILES) $(ALL_FLAGS) -I./include

execute:
	$(BUILD_DIR)/$(EXECUTABLE_NAME)