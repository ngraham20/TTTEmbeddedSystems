// Here, we'll implement the new functions which can manipulate the matrix for TTT


#include "main.h"
#include "sm32f4xx_hal.h"

SPI_HandleTypeDef hspi2;

void slr_init(){
    uint8_t slr[2] = {0x0B, 0x07};
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2,slr,2,100);
	for(int i = 0; i < 50; i++){} // 50 microsegundos
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
}
