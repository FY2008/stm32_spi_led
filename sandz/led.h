#ifndef LED_H
#define LED_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"

/* 数码管位枚举 */
typedef enum{
    GE_BIT,
    SHI_BIT,
    BAI_BIT,
    QIAN_BIT
}LedBIT;
extern uint8_t data[];
extern SPI_HandleTypeDef hspi2;
void hc74959_display(uint16_t num);
#endif