#include "led.h"


/* 数码管显示函数 spi2驱动
*数码管模块是74hc595驱动的，静态显示所以有每位数码管单独一个74hc595
*/
void hc74959_display(uint16_t num){

    uint16_t qian = num / 1000;     // 解析后的千位数字
    uint16_t bai = num / 100 % 10;  // 解析后的百位数字
    uint16_t shi = num /10 %10;     // 解析后的十位数字
    uint16_t ge = num %10;          // 解析后的个位数字

    for (uint8_t j=0;j<4;j++){
      
      switch (j){
        case GE_BIT:
          // 个位
          HAL_SPI_Transmit_IT(&hspi2, &data[ge], 1);     // SPI 输出
          break;
        case SHI_BIT:
          // 十位
          HAL_SPI_Transmit_IT(&hspi2, &data[shi], 1);
          break;
        case BAI_BIT:
          // 百位
          HAL_SPI_Transmit_IT(&hspi2, &data[bai], 1);
          break;
        case QIAN_BIT:
          // 千位
          HAL_SPI_Transmit_IT(&hspi2, &data[qian], 1);
          break;
        default:
          break;
      }
    } // end for

    /* 让锁存输出一个高电平脉冲 */
    HAL_GPIO_WritePin(SPI2_LOAD_GPIO_Port, SPI2_LOAD_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(SPI2_LOAD_GPIO_Port, SPI2_LOAD_Pin, GPIO_PIN_RESET);
} /* end --------- hc74959_display functions ---------------- */