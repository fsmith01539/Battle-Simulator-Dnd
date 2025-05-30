CC = gcc
CPP = g++

SRC_DIR = src
BUILD_DIR = build

TARGET = app

SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

CPP_FLAGS = -Iinclude -Wall 

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CPP) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CPP) -c $(CPP_FLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
