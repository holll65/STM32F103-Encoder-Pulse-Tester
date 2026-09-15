#include "stm32f10x.h"
#include "config_delay.h"
#include "config_encoder.h"
#include "./lcd/bsp_ili9341_lcd.h"

#include <stdio.h>

int main(void)
{
    uint32_t pulse_count = 0;
    uint32_t last_pulse_count = 0;

    char dispBuff[16];

    Delay_Init();

    /******************************
     * LCD初始化
     ******************************/
    ILI9341_Init();

    /* 显示方向 */
    ILI9341_GramScan(6);

    /******************************
     * 编码器初始化
     ******************************/
    Encoder_Pulse_Init();

    Encoder_ClearPulseCount();

    /******************************
     * LCD设置
     ******************************/
    LCD_SetFont(&Font16x24);

    LCD_SetColors(WHITE, BLACK);

    /* 清屏 */
    ILI9341_Clear(
        0,
        0,
        LCD_X_LENGTH,
        LCD_Y_LENGTH
    );

    /******************************
     * 标题
     ******************************/
    LCD_SetTextColor(GREEN);

    ILI9341_DispString_EN(
        20,
        30,
        "ENCODER TEST"
    );

    /******************************
     * PULSE标签
     ******************************/
    LCD_SetTextColor(WHITE);

    ILI9341_DispString_EN(
        20,
        100,
        "PULSE:"
    );

    /******************************
     * 初始脉冲值
     ******************************/
    LCD_SetTextColor(YELLOW);

    ILI9341_DispString_EN(
        130,
        100,
        "0"
    );

    while(1)
    {
        pulse_count = Encoder_GetPulseCount();

        if(pulse_count != last_pulse_count)
        {
            /*
             * 固定10位显示
             * 空余位置自动补空格，
             * 用于清除上一次数字
             */
            sprintf(
                dispBuff,
                "%-10lu",
                (unsigned long)pulse_count
            );

            LCD_SetTextColor(YELLOW);

            ILI9341_DispString_EN(
                130,
                100,
                dispBuff
            );

            last_pulse_count = pulse_count;
        }

        Delay_ms(20);
    }
}