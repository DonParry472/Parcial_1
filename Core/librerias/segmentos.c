#include "segmentos.h"

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