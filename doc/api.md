# API 参考手册

## 1. 游戏核心 (game.h)

### 1.1 游戏初始化
```c
void initGame(void);
```
初始化游戏状态、蛇和食物。

### 1.2 游戏循环
```c
void updateGame(void);
void drawGame(void);
int isGameOver(void);
```
处理游戏主循环相关功能。

### 1.3 输入处理
```c
void handleInput(void);
```
处理键盘输入（WASD控制）。

### 1.4 游戏机制
```c
void generateFood(void);
```
生成新的食物。

## 2. 系统工具 (utils.h)

### 2.1 屏幕控制
```c
void clearScreen(void);
```
清理控制台屏幕。

### 2.2 时间控制
```c
void sleep(int milliseconds);
```
程序延时控制。

## 3. 常量定义

### 3.1 游戏参数
- WIDTH (40) - 游戏区域宽度
- HEIGHT (20) - 游戏区域高度
- SNAKE_MAX_LENGTH (100) - 蛇最大长度

## 4. 全局状态

### 4.1 游戏状态
- snake - 蛇的状态
- food - 食物位置
- score - 当前得分
- gameOver - 游戏结束标志

## 5. 使用示例

### 5.1 基本游戏循环
```c
initGame();
while (!gameOver) {
    handleInput();
    updateGame();
    drawGame();
    sleep(100);
}
```
