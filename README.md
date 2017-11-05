# stm32_spi_led

使用STM32 的SPI驱动数码管模块。数码管模块是一个4位的静态显示模块，芯片是74hc595d
芯片配置使用的是STM32CubeMX。

简单的实现了显示。只有调用hc74959_display(uint16_t num);函数即可。

如显示1234：
hc74959_display(1234);