#include "stm32f10x.h"                  // Device header
//#include "serial.h"

void uaer_uart_init(void)
{

	//USER_InitTypeDef USER_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructurs;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructurs.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructurs.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructurs);
	
	GPIO_InitStructurs.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructurs.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructurs.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructurs);
	
	
	
	
}
