#ifndef __CONFIG_ENCODER_H
#define __CONFIG_ENCODER_H

#include "stm32f10x.h"

extern volatile uint32_t g_encoder_pulse_count;

void Encoder_Pulse_Init(void);
uint32_t Encoder_GetPulseCount(void);
void Encoder_ClearPulseCount(void);

#endif