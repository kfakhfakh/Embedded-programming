#include "stm32f4xx.h"

volatile unsigned short int *RCC_AHB1ENR = (unsigned short int *) 0x40023830;

// l'adresse de register GPIOD_MODER
volatile unsigned  int *GPIOD_MODER = (unsigned int *) 0x40020C00;

// l'adresse de register GPIOA_MODER
volatile unsigned  int *GPIOA_MODER = (unsigned int *) 0x40020000;

// l'adresse de register GPIOD_ODR
volatile unsigned  int *GPIOD_ODR = (unsigned int *) 0x40020C14;

// l'adresse de register GPIOA_IDR
volatile unsigned  int *GPIOA_IDR = (unsigned int *) 0x40020010;


void Delay(volatile unsigned  int  nCount);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  // activer l'horloge de GPIO D
  *RCC_AHB1ENR |= (1<<3) ;
  // activer l'horloge de GPIO A
  *RCC_AHB1ENR |= (1<<0) ;

  // configureation la pin PD12
  *GPIOD_MODER |=  (1<<24);

  // configureation la pin PD13
  *GPIOD_MODER |=  (1<<26);

  // configureation la pin PD14
  *GPIOD_MODER |=  (1<<28);

  // configureation la pin PD15
  *GPIOD_MODER |=  (1<<30);

  // configureation la pin PA1
  *GPIOA_MODER &=  ~(3<<0);


  while(1)
  {

	  /* verifier la valeur de pin 1 */
    if(*(GPIOA_IDR)&(1))
    {/* mettre le pin 12 a 1 */
        *GPIOD_ODR |= 0x1000;

      /* mettre le pin 13 a 1 */
        *GPIOD_ODR |= 0x2000;

        /* mettre le pin 14 a 1 */

        *GPIOD_ODR |= 0x4000;

        /* mettre le pin 15 a 1 */
        *GPIOD_ODR |= 0x8000;

      Delay(0x5FFFFF);

      /* mettre le pin 12 a 0 */
      *GPIOD_ODR &=~ (1<<12);

      /* mettre le pin 13 a 0 */
      *GPIOD_ODR &= ~(1<<13);

      /* mettre le pin 14 a 0 */
      *GPIOD_ODR &=~ (1<<14);

      /* mettre le pin 15 a 0 */
      *GPIOD_ODR &=~ (1<<15);
      Delay(0x5FFFFF);
      }
  }
}
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(  unsigned  int nCount)
{
  for(; nCount != 0; nCount--);
}

/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/
