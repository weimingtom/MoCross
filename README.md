MoCross
=======

Cross Platform Game Engine

### 关于引擎

目标是一个支持跨平台，带有完善的可视化编辑器的3D游戏开发工具。

### 已经实现功能

- 渲染设备
   - OpenGL2.0

- 渲染管道：
   - 简单绘制：
      - VertexColor
      - AmbientColor
      - DiffuseColor
      - ViewDiffuseColor
      - SpecularColor
      - ViewSpecularColor
      - ReflectColor(Cube3d)
   - 阴影绘制：
      - ShadowMapColor
   - 后期处理：
      - Blur

- 渲染技术：
   - 异步空间排序剔除
   - 异步动画播放
   - 实例绘制(支持移动设备)
   - 场景空间合并(静态版本)

### 路线图

- 2014年06月，完成基础代码构架。
- 2014年12月，提供简单的可视化工具。
- 2015年06月，完善可视化工具，提供可用的场景编辑器，界面编辑器。
- 2015年12月，完善引擎，开始追求更高效率和效果。

### 结构说明

- Build：构建内容。
- Document：系统文档。
- Source/Cross：    引擎核心，主要是C++代码构成。
- Source/Document： 引擎文档。
- Source/Library：  引用其他库文件。（包含源码）
- Source/Reference：引用其他库文件。（不包含源码）
- Source/Utility：  工具。(3DSMax导出插件等)
- Platform：平台工具，主要是Java代码构成。目标为引擎提供编译，发布，平台化工具。
- Tools：工具集合，在没有正式编辑前，暂时管理资源，管理配置用，主要是C#代码构成。
- Demo：演示工具

### 文档

正在准备中 ...
[GitHub Wiki](https://github.com/favedit/MoCross/wiki).

### 文件下载

暂无发布版本。
- 提供 \Source\MoCrossSolution.sln 文件，可以在VS2012下编译通过，可以运行 MpTestDemo 实例。
- 可以在Android NDK下编译通过，可以在手机上正常运行。
![MoCross](/Document/Resource/TestDemo01.jpg)

### 更新

- 2014年01月 - 搭建基础库。
- 2014年02月 - 增加资源管理(MoFeatureResource)，图形管理(MoFeatureGraphics)。 
- 2014年03月 - 增加引擎基础(Engine)，引擎2D(Engine2D)，引擎3D(Engine3D)部分
             增加渲染代码生成管理(Shader Template)，完善渲染管道(Render Pipeline)
- 2014年04月 - 增加Mono的C#脚本框架 MoFeatureScript / MoPluginScriptMono

### 关于

- FavEdit => Favorite Edit 表示愿意编辑，写写代码的意思。
- 网页 Stage3D CoolLight - 炫光引擎 的制作者。

### 加入
- 制作引擎的目的不是为了商业化盈利，纯粹是个人兴趣。
- 希望能自己用自己引擎做出有特色的游戏，算是一个梦想吧。
- 现在因为是只有个人制作，能力有限，期望能遇到有同样追求，想做3D引擎的人加入。
