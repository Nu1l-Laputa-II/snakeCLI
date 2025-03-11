#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

// 游戏区域的宽度和高度
#define WIDTH 40      // 游戏界面宽度
#define HEIGHT 20     // 游戏界面高度
#define SNAKE_MAX_LENGTH 100  // 蛇的最大长度

// 位置结构体，用于存储坐标
typedef struct {
    int x;  // x坐标
    int y;  // y坐标
} Position;

// 蛇结构体，包含蛇的所有信息
typedef struct {
    Position body[SNAKE_MAX_LENGTH];  // 蛇身体各节点的位置数组
    int length;                       // 蛇当前的长度
    int direction;                    
    // 蛇的移动方向：
    // 0 = UP    (按键W) - 向上移动
    // 1 = RIGHT (按键D) - 向右移动
    // 2 = DOWN  (按键S) - 向下移动
    // 3 = LEFT  (按键A) - 向左移动
} Snake;

// 全局游戏状态变量
extern int score;
extern int gameOver;

// 游戏核心函数声明

// 初始化游戏状态，包括蛇的初始位置和食物的生成
void initGame(void);

// 更新游戏状态，处理蛇的移动和食物的收集
void updateGame(void);

// 绘制游戏画面，包括边界、蛇和食物
void drawGame(void);

// 检查游戏是否结束，返回1表示结束，0表示继续
int isGameOver(void);

// 在随机位置生成新的食物
void generateFood(void);

// 处理用户输入，改变蛇的移动方向
void handleInput(void);

#endif
