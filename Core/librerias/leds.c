#include "leds.h"

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
        HAL_Delay(500);
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
  