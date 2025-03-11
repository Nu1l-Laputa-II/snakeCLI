# 技术设计文档

## 1. 系统架构
### 1.1 模块划分
- 主程序模块 (main.c)
- 游戏逻辑模块 (game.c/h)
- 工具模块 (utils.c/h)

### 1.2 模块职责
- 主程序：游戏初始化和主循环
- 游戏逻辑：状态管理和核心玩法
- 工具：系统功能封装

## 2. 核心数据结构
### 2.1 游戏对象
```c
// Position - 坐标
typedef struct {
    int x;
    int y;
} Position;

// Snake - 蛇
typedef struct {
    Position body[SNAKE_MAX_LENGTH];
    int length;
    int direction;
} Snake;
```

## 3. 关键算法实现
### 3.1 蛇的移动
1. 头部移动计算
2. 身体跟随逻辑
3. 碰撞检测
4. 垂直方向速度补偿
   - 使用计数器控制垂直移动频率
   - 补偿比例为2:1（与字符高宽比匹配）

### 3.2 食物生成
1. 随机位置生成
2. 有效性验证

## 4. 渲染系统
### 4.1 界面布局
- 游戏边界 (#)
- 蛇身体 (O)
- 食物 (*)
- 得分显示

### 4.2 刷新机制
- 双缓冲渲染
  - 后台缓冲区绘制
  - 原子性显示更新
  - 消除画面闪烁
- 延时控制

### 4.3 双缓冲实现
- 使用 Windows Console API
- CHAR_INFO 数组作为后台缓冲
- WriteConsoleOutput 原子性更新