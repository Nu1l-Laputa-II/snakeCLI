#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define WIDTH 40
#define HEIGHT 20
#define SNAKE_MAX_LENGTH 100

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position body[SNAKE_MAX_LENGTH];
    int length;
    int direction;  // 0:up, 1:right, 2:down, 3:left
} Snake;

void initGame(void);
void updateGame(void);
void drawGame(void);
int isGameOver(void);
void generateFood(void);
void handleInput(void);

#endif
