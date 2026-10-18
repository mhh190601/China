# 国庆节 C++ 窗口特效程序

这是一个使用 C++ 与 EasyX 图形库编写的国庆节主题桌面特效程序。包含绝美的粒子动画、烟花爆炸效果与自动渐显功能。

## 📥 直接体验（普通用户）

如果你只是想欣赏效果，无需配置任何开发环境：
1. 点击本仓库右侧的 **[Releases]** 标签页。
2. 下载最新版本的 `NationalDay.exe`。
3. 双击即可直接运行（已采用静态链接打包，免安装）。

## ✨ 功能特性

- **沉浸式图形界面**：使用 EasyX 创建大尺寸/全屏窗口。
- **粒子系统**：实时演算的烟花爆炸、粒子重力与空气阻力。
- **色彩渲染**：采用 24 位真彩色与渐变插值，画面绚丽。
- **自动安全退出**：动画播放结束后，自动清理资源并安全关闭。

## 🛠️ 源码构建（开发者）

如果你想修改代码或自行编译，请参考以下步骤：

### 环境要求
- **操作系统**：Windows 10 / 11
- **编译器**：支持 C++17 或更高版本的 MSVC (Visual Studio 2019/2022)
- **依赖库**：[EasyX 图形库](https://easyx.cn/)（需提前安装）

### 方式一：使用 Visual Studio
1. 打开 Visual Studio，新建一个“空项目”。
2. 将 `national_day.cpp` 添加到源文件中。
3. 确保项目属性中的“字符集”设置为 **Unicode**，C++ 语言标准设为 **C++17**。
4. 按 `F5` 运行。

### 方式二：使用命令行 (MSVC)
打开 *x64 Native Tools Command Prompt for VS*，进入代码目录执行：
```bash
cl /EHsc /std:c++17 /utf-8 national_day.cpp user32.lib gdi32.lib
运行编译出的程序：

bash
.\national_day.exe
📂 项目结构
text
NationalDay/
├── national_day.cpp   # 核心源码（包含图形渲染、粒子算法、主循环）
├── README.md          # 项目说明文档
├── LICENSE            # 开源协议 (MIT)
└── .gitignore         # 忽略编译产物（*.exe, *.obj 等）
📄 开源协议
本项目基于 MIT License 协议开源。