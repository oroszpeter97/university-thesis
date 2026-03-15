# Root Makefile for building and running the project
# Usage:
#   make build     - configure and build
#   make run       - run the executable (after build)
#   make buildrun  - build and then run
#   make clean     - remove build output

# Directory for build output
BUILD_DIR := out
# Name of the executable (update if different)
EXECUTABLE := university_thesis
# Path to the executable after build
EXEC_PATH := $(BUILD_DIR)/$(EXECUTABLE)

.PHONY: all build run buildrun clean

all: build

build:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..
	cd $(BUILD_DIR) && $(MAKE)


run:
	@if [ -x "$(EXEC_PATH)" ]; then \
		echo "Running $(EXEC_PATH)"; \
		$(EXEC_PATH); \
	else \
		echo "Executable not found. Please run 'make build' first."; \
	fi

buildrun: build run

clean:
	rm -rf $(BUILD_DIR)
