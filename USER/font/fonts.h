#ifndef __FONT_H
#define __FONT_H

#include "stm32f10x.h"

typedef struct _tFont
{
    const uint8_t *table;
    uint16_t Width;
    uint16_t Height;

} sFONT;

extern sFONT Font24x32;
extern sFONT Font16x24;
extern sFONT Font8x16;

/* 中文尺寸定义先保留，防止LCD驱动引用 */
#define WIDTH_CH_CHAR    16
#define HEIGHT_CH_CHAR   16

#define LINE(x)  ((x) * (((sFONT *)LCD_GetFont())->Height))
#define LINEY(x) ((x) * (WIDTH_CH_CHAR))

#endif