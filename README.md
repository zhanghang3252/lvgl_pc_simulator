# lvgl_pc_simulator



## 项目介绍
    本项目是基于电脑端的LVGL模拟器，使用需要安装SDL2库，具体环境搭建可参照：https://blog.csdn.net/weixin_49337111/article/details/136536375
    **注意一定要有SDL2库**
## 项目完成情况
    1：实现在线模拟运行
    2：实现基于NXP公司的GUI-Guider软件实现GUI代码生成

## BUG解决
    GUI-Guider生成的代码有些许bug比如在更新页面的时候会涉及到从新绘制的情况，导致界面卡住或控件不能控制
    因为在GUI-Guider生成的gui_guider.c中的ui_load_scr_animation函数，重绘了界面，使得界面的原有状态被破坏。
