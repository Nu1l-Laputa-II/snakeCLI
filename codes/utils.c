#include "utils.h"
#include <windows.h>

// 清屏函数
void clearScreen() {
    // 获取标准输出设备句柄
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // 定义屏幕坐标，起始位置为 (0, 0)
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // 获取控制台屏幕缓冲区信息
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    // 计算屏幕缓冲区的大小
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    // 用空格填充整个屏幕缓冲区
    FillConsoleOutputCharacter(hConsole, ' ', dwConSize, coordScreen, &cCharsWritten);
    // 再次获取控制台屏幕缓冲区信息
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    // 用当前的属性填充整个屏幕缓冲区
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    // 将光标位置设置到屏幕的左上角
    SetConsoleCursorPosition(hConsole, coordScreen);
}

// 暂停函数
void sleep(int milliseconds) {
    // 调用 Windows API 的 Sleep 函数，暂停指定的毫秒数
    Sleep(milliseconds);
}