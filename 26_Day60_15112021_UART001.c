/*
===============================================================================
 Name        : 26_Day60_15112021_UART001.c

 Description : Program to demonstrate the UART0 Transmission in polling method



 Layered Architecture used for this project
 ************************************
 Application layer-26_Day60_15112021_UART001.c
 ************************************
 Board layer -  configboard.h
 ************************************
 Low level drivers or chip level - pinmux.c/.h,uart.c/.h
 ************************************
 Hardware
 ************************************
===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "pinmux.h"
#include "uart.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{
	vPinmuxInitialize();
	vUARTInitialize(UART0,UART_0,BAUDRATE_9600);

}

/**
  * @brief  Crude Delay
  * @retval none
  */
void vAppDelay(uint32_t count)
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<0xA00;j++);
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();


  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {

		vUARTPutCharBlocking(UART0, 'T');
		vAppDelay(0x200);

		vUARTPutStringBlocking(UART0, "TRANSIOT UART TESTING\n");
		vAppDelay(0x200);

		vUARTPutNumBlocking(UART0, 42, BINARY);
		vAppDelay(0x200);

		vUARTPrintfBlocking(UART0, "%d, %c, %o, %x\n", 42, 42, 42, 42);
		vAppDelay(0x200);
  }
  /* End of Application entry point */
}




