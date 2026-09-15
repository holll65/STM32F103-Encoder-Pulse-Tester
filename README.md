# STM32F103-Encoder-Pulse-Tester

## 项目说明

本工程用于 STM32F103 编码器脉冲采集测试，主要功能包括：

- STM32F103ZET6
- 采集增量式编码器 A 相脉冲
- 使用外部中断 EXTI 进行脉冲计数
- ILI9341 LCD 实时显示累计脉冲数
- 用于检测编码器是否存在丢脉冲
- 支持后续扩展 A/B/Z 三相信号检测
- 支持后续增加频率、转速、丢脉冲判断等功能

当前测试主要针对编码器 A 相脉冲。

编码器参数示例：

- 分辨率：2500 PPR
- 每转 A 相理论脉冲数：2500
- 单圈测试时，可通过累计脉冲数判断是否存在明显丢脉冲

---

## 文件结构

```text
STM32F103-Encoder-Pulse-Tester/

├── .vscode/
│   ├── c_cpp_properties.json
│   ├── settings.json
│   ├── tasks.json
│   └── launch.json
│
├── platformio.ini
├── Makefile
│
├── CMSIS/
├── FWlib/
│
└── USER/
    ├── main.c
    ├── config_encoder.c
    ├── config_encoder.h
    ├── config_delay.c
    ├── config_delay.h
    ├── stm32f10x_it.c
    ├── stm32f10x_it.h
    │
    ├── lcd/
    │   ├── bsp_ili9341_lcd.c
    │   └── bsp_ili9341_lcd.h
    │
    └── font/
        ├── fonts.c
        └── fonts.h