OBJS = sdlTest.cpp

OBJ_NAME = sdlTest

CC = g++

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lSDL2

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

