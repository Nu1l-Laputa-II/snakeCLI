# 命令行贪吃蛇 (Snake CLI Game)

一个基于C语言开发的命令行贪吃蛇游戏，提供经典的贪吃蛇玩法体验。

## 目录
- [功能特点](#功能特点)
- [系统架构](#系统架构)
- [开发环境](#开发环境)
- [安装说明](#安装说明)
- [使用说明](#使用说明)
- [项目结构](#项目结构)
- [开发文档](#开发文档)

## 功能特点

### 游戏玩法
- 经典贪吃蛇移动控制
- 食物随机生成
- 实时分数显示
- 碰撞检测（边界和自身）

### 系统功能
- 命令行界面渲染
- 双缓冲消除闪烁
- 键盘控制响应
- 游戏状态管理
- 实时画面刷新

### 游戏特性
- 采用双缓冲技术，画面流畅无闪烁
- 实时画面更新，响应迅速

## 系统架构

系统采用模块化设计，主要包含以下模块：
- 主程序模块 (main.c)
- 游戏逻辑模块 (game.c/h)
- 系统工具模块 (utils.c/h)

## 安装说明

1. 克隆代码仓库：
```bash
git clone https://github.com/Nu1l-Laputa-II/snakeCLI.git
cd snakeCLI
```

2. 编译项目：
```bash
gcc codes/main.c codes/game.c codes/utils.c -o snake
```

3. 运行程序：
```bash
./snake
```

## 使用说明

### 游戏控制
- W键：向上移动
- S键：向下移动
- A键：向左移动
- D键：向右移动

### 游戏规则
- 通过WASD控制蛇的移动方向
- 吃到食物（*）可以增长长度和分数
- 撞到墙壁（#）或自身会导致游戏结束
- 每个食物得分10分

## 项目结构

```
snakeCLI/
├── codes/          # 源代码目录
│   ├── main.c      # 主程序
│   ├── game.h      # 游戏逻辑头文件
│   ├── game.c      # 游戏逻辑实现
│   ├── utils.h     # 工具函数头文件
│   └── utils.c     # 工具函数实现
├── doc/            # 项目文档目录
│   ├── design.md   # 设计框架文件
│   └── api.md      # 接口设计文件
└── README.md       # 项目说明文档
```

## 开发文档

详细的API文档和开发指南请参考：
- [设计文档](doc/design.md)
- [API文档](doc/api.md)

## 注意事项

1. 游戏限制
   - 游戏区域：40x20
   - 最大蛇长：100
   - 刷新速度：100ms

2. 运行要求
   - Windows系统
   - 支持ANSI的命令行终端

## 作者

[Nu1l-Laputa-II]

## 许可证

MIT License

## 问题反馈

如有问题，请提交issue：
- GitHub Issues: [issues page](https://github.com/Nu1l-Laputa-II/snakeCLI/issues)
