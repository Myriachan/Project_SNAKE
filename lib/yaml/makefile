# Sources
SRC_DIR = . libyaml
OBJS = $(foreach dir,$(SRC_DIR),$(subst .cpp,.o,$(wildcard $(dir)/*.cpp))) $(foreach dir,$(SRC_DIR),$(subst .c,.o,$(wildcard $(dir)/*.c)))

INC_DIR = ..
INCS = $(foreach dir,$(INC_DIR), -I"$(dir)/")

# Compiler Settings
CXXFLAGS = -std=c++11 $(INCS) -D__STDC_FORMAT_MACROS -Wall -Wno-unused-but-set-variable -Wno-unused-value
ifeq ($(OS),Windows_NT)
	# Windows Only Flags/Libs
	CC = x86_64-w64-mingw32-gcc
	CXX = x86_64-w64-mingw32-g++
	CFLAGS += 
	CXXFLAGS += 
else
	# *nix Only Flags/Libs
	CFLAGS += 
	CXXFLAGS += 
endif

# Output
OUTPUT = ../lib$(shell basename $(CURDIR)).a

main: build

rebuild: clean build

build: $(OBJS)
	ar cr -o $(OUTPUT) $(OBJS)

clean:
	rm -rf $(OUTPUT) $(OBJS)