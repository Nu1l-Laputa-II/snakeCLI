#ifndef UTILS_H
#define UTILS_H

// 清理控制台屏幕，用于更新游戏画面
void clearScreen(void);

// 控制游戏速度的延时函数
// @param milliseconds: 暂停的毫秒数
void sleep(int milliseconds);

// 初始化双缓冲
void initDoubleBuffer(void);
// 清理双缓冲
void cleanupDoubleBuffer(void);
// 切换到后台缓冲区进行绘制
void writeToBuffer(int x, int y, char ch);
// 将后台缓冲区内容显示到屏幕
void showBuffer(void);

#endif
