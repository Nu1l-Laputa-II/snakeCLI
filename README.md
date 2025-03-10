# Snake CLI Game

命令行版贪吃蛇游戏 - 使用纯C语言实现。

## 快速开始

### 编译
```bash
gcc codes/main.c codes/game.c codes/utils.c -o snake
```

### 运行
```bash
.\snake
```

## 游戏操作
- W: 上
- S: 下
- A: 左
- D: 右

## 核心功能
- 经典贪吃蛇玩法
- 命令行界面
- 实时分数显示
- 碰撞检测

## 系统要求
- Windows 操作系统
- GCC 编译器
- 等宽字体终端

## 文档
- [设计文档](doc/design.md) - 项目架构和实现细节
- [API文档](doc/api.md) - API 接口说明

## 目录结构
```
snakeCLI/
├── codes/          # 源代码
├── doc/            # 项目文档
└── README.md       # 项目说明
```
