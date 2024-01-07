CXX = g++
CC = $(CXX)

# CXXFLAGS = -Wall -Werror -Wconversion -g -Wextra
CXXFLAGS+= -std=c++17
LIBS=-lsfml-graphics -lsfml-window -lsfml-system


SRCS := $(wildcard game_arkenoid/*.cpp)
TARGETS := $(notdir $(SRCS:.cpp=))


check: main
	./main


main:main.o $(LIBS) Ball.o Block.o BlocksField.o Game.o GlobalObjects.o Paddle.o screen.o



all: $(TARGETS)
$(TARGETS): $(STUFF)

clean:
	@echo "cleaning up"
	$(RM)  *.o main

