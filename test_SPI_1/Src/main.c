/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/*static uint8_t presets[MAX_PRESET_NUMB][MAX_DIGITS] = {
   {0x18, 0x18, 0x18, 0x99, 0xDB, 0x7E, 0x3C, 0x18}, *< Arrow dx.
   {0x18, 0x3C, 0x7E, 0xDB, 0x99, 0x18, 0x18, 0x18}, *< Arrow sx.
   {0x00, 0x20, 0x44, 0x40, 0x40, 0x44, 0x20, 0x00}, *< Happy face.
   {0x00, 0x20, 0x14, 0x10, 0x10, 0x14, 0x20, 0x00}, *< Sad face.
   {0x00, 0x00, 0x00, 0xDF, 0xDF, 0x00, 0x00, 0x00}, *< Exclamation point.
   {0x24, 0x66, 0xE7, 0xE7, 0xE7, 0xE7, 0x66, 0x24}, *< Negate.
   {0x00, 0x84, 0x86, 0xFF, 0xFF, 0x80, 0x80, 0x00}, *< 1.
   {0x00, 0x86, 0xC7, 0xE1, 0xB1, 0x9F, 0x8E, 0x00},*< 2.
   {0x00, 0x00, 0x42, 0xC3, 0xDB, 0xFF, 0x66, 0x00}, *< 3.
   {0x00, 0x3F, 0x3F, 0x20, 0x20, 0xF8, 0xF8, 0x00}, *< 4.
   {0x00, 0xDF, 0xDB, 0xDB, 0xDB, 0xFB, 0x71, 0x00}, *< 5.
   {0x00, 0x7E, 0xFF, 0x89, 0x89, 0x89, 0x70, 0x00}, *< 6.
   {0x00, 0x03, 0x03, 0xE3, 0xFB, 0x1F, 0x07, 0x00}, *< 7.
   {0x00, 0x76, 0xFF, 0x99, 0x99, 0xFF, 0x76, 0x00}, *< 8.
   {0x00, 0x8E, 0x91, 0x91, 0x91, 0xFF, 0x7E, 0x00}, *< 9.
   {0x00, 0x7E, 0xFF, 0x81, 0x81, 0xFF, 0x7E, 0x00}, *< 0.
   {0x00, 0x06, 0x76, 0x38, 0x38, 0x76, 0x06, 0x00}  *< Creeper face.
};*/
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
/* USER CODE BEGIN 1 */
void slr_init(){
    uint8_t slr_reg1[2] = {0x0B, 0x07};
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2,slr_reg1,2,100);
	for(int i = 0; i < 50; i++){} // 50 microsegundos
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
}

void intensity_init()
{
    uint8_t intensity_reg1[2] = {0x05,0x0F};
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2,intensity_reg1,2,100);
	for(int i = 0; i < 50; i++){} // 50 microsegundos
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
}

void decode_init(){
    uint8_t decode_reg1[2] = {0x09, 0x00};
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2,decode_reg1,2,100);
	for(int i = 0; i < 50; i++){} // 50 microsegundos
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
}

void shutdown_init(){
    uint8_t shutdown_reg1[2] = {0x0C, 0x01};
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2,shutdown_reg1,2,100);
	for(int i = 0; i < 50; i++){} // 50 microsegundos
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
}

void spi_init()
{
	shutdown_init();
	slr_init();
	intensity_init();
	decode_init();
}

void transmit(uint8_t column, uint8_t data){
    uint8_t data_string [2]= {column,data};
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2,data_string,2,100);
    for(int i = 0; i < 50; i++){} // 50 microsegundos
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
}

void display_image_array(const uint8_t data[]){
    const int MAX_DIGITS = 8;
   // uint8_t column;
//    for (uint8_t i = 0x00; i < MAX_DIGITS; i++){
//        switch (i){
//            case 0: column=0x01;break;
//            case 1: column=0x02;break;
//            case 2: column=0x03;break;
//            case 3: column=0x04;break;
//            case 4: column=0x05;break;
//            case 5: column=0x06;break;
//            case 6: column=0x07;break;
//            case 7: column=0x08;break;
//            default: column=0x00;break;
//        }
    for(int j = 0; j < MAX_DIGITS; j++){
        transmit(j+1,data[j]);
    }
}

void apply_board(uint8_t *temp, uint8_t *board)
{
	const int MAX_LED = 8;
	for (int i = 0; i < MAX_LED; i++)
	{
		board[i] += temp[i];
	}
	return;
}

void clear_screen()
{
	const uint8_t clearData[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	display_image_array(clearData);
}

void flash_once(){
    transmit(0x0C,0x00);
    //  HAL_Delay(10);
    HAL_Delay(1);
    transmit(0x0C,0X01);
    HAL_Delay(100);
    transmit(0x09,0x00);
    transmit(0x0B,0x07);

}
/* USER CODE END 1 */
int main(void)
{


    /* MCU Configuration----------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_SPI2_Init();

    /* USER CODE BEGIN 2 */

    clear_screen();
    spi_init();

    // initialize global variables
    int spaces[3][3] = {{0}};
    uint8_t board[8] = {0x24, 0x24, 0xFF, 0x24, 0x24, 0xFF, 0x24, 0x24};
    uint8_t temp_board[8] = {0};
    uint8_t piece_temp = 0x01;
    temp_board[6] += piece_temp;
    temp_board[7] += piece_temp << 1;
    apply_board(&temp_board, &board);

    HAL_Delay(1);

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */

    while (1){
        display_image_array(board);
        HAL_Delay(10);
    }
}


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    /* USER CODE END 3 */



/**
  * @brief System Clock Configuration
  * @retval None
  */
    void SystemClock_Config(void)
    {

        RCC_OscInitTypeDef RCC_OscInitStruct;
        RCC_ClkInitTypeDef RCC_ClkInitStruct;

        /**Configure the main internal regulator output voltage
        */
        __HAL_RCC_PWR_CLK_ENABLE();

        __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

        /**Initializes the CPU, AHB and APB busses clocks
        */
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
        RCC_OscInitStruct.HSIState = RCC_HSI_ON;
        RCC_OscInitStruct.HSICalibrationValue = 16;
        RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
        RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
        RCC_OscInitStruct.PLL.PLLM = 8;
        RCC_OscInitStruct.PLL.PLLN = 80;
        RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
        RCC_OscInitStruct.PLL.PLLQ = 7;
        if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
        {
            _Error_Handler(__FILE__, __LINE__);
        }

        /**Initializes the CPU, AHB and APB busses clocks
        */
        RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                      |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
        RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
        RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV16;
        RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
        RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

        if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
        {
            _Error_Handler(__FILE__, __LINE__);
        }

        /**Configure the Systick interrupt time
        */
        HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

        /**Configure the Systick
        */
        HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

        /* SysTick_IRQn interrupt configuration */
        HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
    }

/* SPI2 init function */
    static void MX_SPI2_Init(void)
    {

        /* SPI2 parameter configuration*/
        hspi2.Instance = SPI2;
        hspi2.Init.Mode = SPI_MODE_MASTER;
        hspi2.Init.Direction = SPI_DIRECTION_1LINE;
        hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
        hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
        hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
        hspi2.Init.NSS = SPI_NSS_SOFT;
        hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
        hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
        hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
        hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
        hspi2.Init.CRCPolynomial = 10;
        if (HAL_SPI_Init(&hspi2) != HAL_OK)
        {
            _Error_Handler(__FILE__, __LINE__);
        }

    }

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
     PC3   ------> I2S2_SD
     PA4   ------> I2S3_WS
     PA5   ------> SPI1_SCK
     PB10   ------> I2S2_CK
     PB14   ------> TIM8_CH2N
     PC7   ------> I2S3_MCK
     PA9   ------> USB_OTG_FS_VBUS
     PA10   ------> USB_OTG_FS_ID
     PA11   ------> USB_OTG_FS_DM
     PA12   ------> USB_OTG_FS_DP
     PC10   ------> I2S3_CK
     PC12   ------> I2S3_SD
     PB6   ------> I2C1_SCL
     PB9   ------> I2C1_SDA
*/
    static void MX_GPIO_Init(void)
    {

        GPIO_InitTypeDef GPIO_InitStruct;

        /* GPIO Ports Clock Enable */
        __HAL_RCC_GPIOE_CLK_ENABLE();
        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOH_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_GPIOD_CLK_ENABLE();

        /*Configure GPIO pin Output Level */
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);

        /*Configure GPIO pin Output Level */
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

        /*Configure GPIO pin Output Level */
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                                 |GPIO_PIN_4, GPIO_PIN_RESET);

        /*Configure GPIO pin Output Level */
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);

        /*Configure GPIO pin : PE3 */
        GPIO_InitStruct.Pin = GPIO_PIN_3;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

        /*Configure GPIO pin : PC0 */
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        /*Configure GPIO pin : PC3 */
        GPIO_InitStruct.Pin = GPIO_PIN_3;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        /*Configure GPIO pin : PA0 */
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /*Configure GPIO pin : PA4 */
        GPIO_InitStruct.Pin = GPIO_PIN_4;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /*Configure GPIO pin : PA5 */
        GPIO_InitStruct.Pin = GPIO_PIN_5;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /*Configure GPIO pin : PB2 */
        GPIO_InitStruct.Pin = GPIO_PIN_2;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /*Configure GPIO pin : PB10 */
        GPIO_InitStruct.Pin = GPIO_PIN_10;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /*Configure GPIO pin : PB14 */
        GPIO_InitStruct.Pin = GPIO_PIN_14;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /*Configure GPIO pins : PD12 PD13 PD14 PD15
                                 PD4 */
        GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                              |GPIO_PIN_4;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        /*Configure GPIO pins : PC7 PC10 PC12 */
        GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_10|GPIO_PIN_12;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        /*Configure GPIO pin : PA9 */
        GPIO_InitStruct.Pin = GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /*Configure GPIO pins : PA10 PA11 PA12 */
        GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /*Configure GPIO pin : PD5 */
        GPIO_InitStruct.Pin = GPIO_PIN_5;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        /*Configure GPIO pins : PB6 PB9 */
        GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /*Configure GPIO pin : PB8 */
        GPIO_InitStruct.Pin = GPIO_PIN_8;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /*Configure GPIO pin : PE1 */
        GPIO_InitStruct.Pin = GPIO_PIN_1;
        GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    }

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
    void _Error_Handler(char *file, int line)
    {
        /* USER CODE BEGIN Error_Handler_Debug */
        /* User can add his own implementation to report the HAL error return state */
        while(1)
        {
        }
        /* USER CODE END Error_Handler_Debug */
    }

#ifdef  USE_FULL_ASSERT
    /**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
