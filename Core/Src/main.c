/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t pasos=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void delay_us_dwt_init()
{
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    pasos=(HAL_RCC_GetSysClockFreq()/1000000);//le el cristal pasa a us

}

//retardo por debbuger
void delay_us_dwt(uint32_t reta)
{

DWT->CYCCNT=0;
while( DWT->CYCCNT<=pasos*reta);//multiplica por us
}

void Sound_play(uint32_t frec,uint32_t dura)
{
	uint32_t dela=500000/frec;//  la mitad de un mega
	uint32_t  repe=frec*dura/1000;// calcula cuantas veces se repite

		while(repe--)
	  {
	HAL_GPIO_WritePin(PAR_GPIO_Port, PAR_Pin,1);
	delay_us_dwt(dela);
	  HAL_GPIO_WritePin(PAR_GPIO_Port, PAR_Pin,0);
	  delay_us_dwt(dela);
      }

}

void epona(void)
{
    uint32_t duracion = 250;   // Duración de cada nota en ms

    uint16_t melodia[] =
    {
        1175, 988, 880, 1175, 988, 880, 1175, 988, 880,
        988, 880, 740, 698, 740, 1109, 1175, 988, 1175,
        1175, 1109, 988, 880,

        1175, 988, 880, 1175, 988, 880, 1175, 988, 880,
        988, 880, 740, 698, 740, 988, 1109, 1175, 1175,
        1319, 1175,

        932, 932, 932, 932, 932, 1047,
        932, 932, 880, 880, 1047, 698,

        784, 784, 784, 784, 784,
        880, 932, 880, 880, 880,

        932, 932, 932, 932, 932, 1047,
        932, 932, 880, 880, 1047, 698,

        784, 784, 784, 784, 784,
        880, 932, 880, 880,

        1175, 988, 880, 1175, 988, 880, 1175, 988, 880,
        988, 880, 740, 698, 740, 988, 1109, 1175,
        1175, 1175, 1109, 988, 880,

        1175, 988, 880, 1175, 988, 880, 1175, 988, 880,
        988, 880, 740, 698, 740, 988, 1109, 1175,
        1175, 1175, 1319, 1175
    };

    uint32_t numero_notas = sizeof(melodia) / sizeof(melodia[0]);

    for(uint32_t i = 0; i < numero_notas; i++)
    {
        Sound_play(melodia[i], duracion);
    }
}

void cielitolindo()
{
    // De la Sierra Morena
    Sound_play(523, 350);   // DO5
    Sound_play(523, 250);   // DO5
    Sound_play(440, 250);   // LA4
    Sound_play(494, 250);   // SI4
    Sound_play(392, 400);   // SOL4


    // Cielito lindo vienen bajando
    Sound_play(523, 250);   // DO5
    Sound_play(523, 250);   // DO5
    Sound_play(440, 250);   // LA4
    Sound_play(494, 250);   // SI4
    Sound_play(392, 500);   // SOL4


    // Un par de ojitos negros
    Sound_play(523, 250);   // DO5
    Sound_play(523, 250);   // DO5
    Sound_play(440, 350);   // LA4
    Sound_play(494, 250);   // SI4
    Sound_play(392, 250);   // SOL4
    Sound_play(349, 250);   // FA4
    Sound_play(294, 500);   // RE4


    // Cielito lindo de contrabando
    Sound_play(494, 250);   // SI4
    Sound_play(494, 250);   // SI4
    Sound_play(494, 250);   // SI4
    Sound_play(494, 250);   // SI4
    Sound_play(440, 250);   // LA4
    Sound_play(349, 250);   // FA4
    Sound_play(294, 250);   // RE4
    Sound_play(294, 250);   // RE4
    Sound_play(330, 250);   // MI4

    Sound_play(349, 250);   // FA4
    Sound_play(392, 250);   // SOL4
    Sound_play(392, 250);   // SOL4
    Sound_play(392, 250);   // SOL4
    Sound_play(349, 250);   // FA4
    Sound_play(330, 250);   // MI4
    Sound_play(294, 250);   // RE4
    Sound_play(262, 600);   // DO4


    // ¡Ay, ay, ay, ay!
    Sound_play(659, 500);   // MI5
    Sound_play(587, 300);   // RE5
    Sound_play(523, 250);   // DO5
    Sound_play(440, 600);   // LA4


    // Canta y no llores
    Sound_play(587, 350);   // RE5
    Sound_play(587, 200);   // RE5
    Sound_play(523, 200);   // DO5
    Sound_play(659, 300);   // MI5
    Sound_play(523, 500);   // DO5


    // Porque cantando se alegran
    Sound_play(392, 250);   // SOL4
    Sound_play(440, 300);   // LA4
    Sound_play(392, 250);   // SOL4
    Sound_play(440, 250);   // LA4
    Sound_play(440, 250);   // LA4
    Sound_play(392, 250);   // SOL4
    Sound_play(698, 300);   // FA5
    Sound_play(698, 300);   // FA5


    // Cielito lindo, los corazones
    Sound_play(587, 350);   // RE5
    Sound_play(494, 250);   // SI4
    Sound_play(392, 250);   // SOL4
    Sound_play(440, 300);   // LA4
    Sound_play(440, 250);   // LA4
    Sound_play(392, 250);   // SOL4
    Sound_play(349, 250);   // FA4
    Sound_play(330, 250);   // MI4
    Sound_play(294, 250);   // RE4
    Sound_play(262, 600);   // DO4
}

void patron1()
{
    HAL_GPIO_TogglePin(GPIOB, LED1_Pin);
    HAL_Delay(100);
    HAL_GPIO_TogglePin(GPIOB, LED2_Pin);
    HAL_Delay(100);
    HAL_GPIO_TogglePin(GPIOB, LED3_Pin);
    HAL_Delay(100);
    HAL_GPIO_TogglePin(GPIOB, LED4_Pin);
    HAL_Delay(100);
}

void patron2()
{
    HAL_GPIO_TogglePin(GPIOB, LED4_Pin);
    HAL_Delay(100);
    HAL_GPIO_TogglePin(GPIOB, LED3_Pin);
    HAL_Delay(100);
    HAL_GPIO_TogglePin(GPIOB, LED2_Pin);
    HAL_Delay(100);
    HAL_GPIO_TogglePin(GPIOB, LED1_Pin);
    HAL_Delay(100);
}

 void patron3(int repeticiones)
{
    int contador = 0;

    while (contador < repeticiones)
    {
        HAL_Delay(500);
        HAL_GPIO_TogglePin(GPIOB, LED2_Pin);
        HAL_Delay(500);

        HAL_GPIO_TogglePin(GPIOB, LED4_Pin);
        HAL_Delay(500);

        HAL_GPIO_TogglePin(GPIOB, LED3_Pin);
        HAL_Delay(500);

        HAL_GPIO_TogglePin(GPIOB, LED1_Pin);
        HAL_Delay(500);

        contador++;
    }
}

 void patron4(int velocidad, int repeticiones)
  {
    for (int i = 0; i < repeticiones; i++)
    {
        HAL_Delay(500)
        HAL_GPIO_WritePin(GPIOB, LED4_Pin, GPIO_PIN_SET);
        HAL_Delay(velocidad);
        HAL_GPIO_WritePin(GPIOB, LED4_Pin, GPIO_PIN_RESET);

        HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_SET);
        HAL_Delay(velocidad);
        HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_RESET);

        HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_SET);
        HAL_Delay(velocidad);
        HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_RESET);

        HAL_GPIO_WritePin(GPIOB, LED1_Pin, GPIO_PIN_SET);
        HAL_Delay(velocidad);
        HAL_GPIO_WritePin(GPIOB, LED1_Pin, GPIO_PIN_RESET);
    }
  }

void suero(uint16_t t)
{
  GPIOA->ODR = 0b10010010;
  HAL_Delay(t);
  GPIOA->ODR = 0b11000001;
  HAL_Delay(t);
  GPIOA->ODR = 0b10000110;
  HAL_Delay(t);
  GPIOA->ODR = 0b10101111;
  HAL_Delay(t);
  GPIOA->ODR = 0b11000000;
  HAL_Delay(t);
}

void fail()
{
  
  GPIOA->ODR = 0x8E;
  HAL_Delay(500);
  GPIOA->ODR = 136;
  HAL_Delay(500);
  GPIOA->ODR = 0b11111001;
  HAL_Delay(500);
  GPIOA->ODR = 199;
  HAL_Delay(500);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  delay_us_dwt_init();
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  patron3(5);
  HAL_Delay(500);
  patron4(350, 5);

  while (1)
  {
    /* USER CODE END WHILE */
    suero(1000);
    fail();
    patron1();
    HAL_Delay(500);
    patron2();
    HAL_Delay(500);
    cielitolindo();
    HAL_Delay(500);
    epona();
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DPA_Pin|DPB_Pin|DPC_Pin|DPD_Pin
                          |DPE_Pin|DPF_Pin|DPG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, PAR_Pin|LED1_Pin|LED2_Pin|LED3_Pin
                          |LED4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DPA_Pin DPB_Pin DPC_Pin DPD_Pin
                           DPE_Pin DPF_Pin DPG_Pin */
  GPIO_InitStruct.Pin = DPA_Pin|DPB_Pin|DPC_Pin|DPD_Pin
                          |DPE_Pin|DPF_Pin|DPG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PAR_Pin LED1_Pin LED2_Pin LED3_Pin
                           LED4_Pin */
  GPIO_InitStruct.Pin = PAR_Pin|LED1_Pin|LED2_Pin|LED3_Pin
                          |LED4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
