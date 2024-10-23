CC=gcc
FLAGS=-Wall -Werror -lm

run: build
	./main

build: main.c
	$(CC) $^ $(FLAGS) -o main