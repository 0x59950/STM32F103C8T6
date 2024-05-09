#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"
#include "FreeRTOS.h"
#include "task.h"
#include "misc.h"


//#define NULL ((void *)0)


char c = 0;
int i = 0;

// #define SysTick_CLKSource_HCLK_Div8    ((u32)0xFFFFFFFB)
// #define SysTick_CLKSource_HCLK         ((u32)0x00000004)


/*******************************************************************************
* Function Name  : SysTick_CLKSourceConfig
* Description    : Configures the SysTick clock source.
* Input          : - SysTick_CLKSource: specifies the SysTick clock source.
*                    This parameter can be one of the following values:
*                       - SysTick_CLKSource_HCLK_Div8: AHB clock divided by 8
*                         selected as SysTick clock source.
*                       - SysTick_CLKSource_HCLK: AHB clock selected as
*                         SysTick clock source.
* Output         : None
* Return         : None
*******************************************************************************/
// void SysTick_CLKSourceConfig(u32 SysTick_CLKSource)
// {
//   /* Check the parameters */
//   // assert(IS_SYSTICK_CLK_SOURCE(SysTick_CLKSource));

//   if (SysTick_CLKSource == SysTick_CLKSource_HCLK)
//   {
//     SysTick->CTRL |= SysTick_CLKSource_HCLK;
//   }
//   else
//   {
//     SysTick->CTRL &= SysTick_CLKSource_HCLK_Div8;
//   }
// }


void run1(void *d)
{
	// i++;
	while(1)
	{
		i++;
		vTaskDelay(200);
		i--;
		vTaskDelay(200);
	}
}

void run2(void *d)
{
	c++;
	while(1)
	{
		c++;
		vTaskDelay(200);
	}
}

int main(void)
{
#if 0		//reg
	RCC->APB2ENR = 0x00000010;
	GPIOC->CRH = 0x00300000;
	GPIOC->ODR = 0x00000000;
#elif 0
	GPIO_InitTypeDef GPIO_InitStructure = 
	{

		GPIO_Pin_13,
		GPIO_Speed_50MHz,
		GPIO_Mode_Out_PP
	};

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
#endif



#if 1
	/* Start with the clocks in their expected state. */
	RCC_DeInit();
	
	/* Enable HSE (high speed external clock). */
	RCC_HSEConfig( RCC_HSE_ON );

	/* Wait till HSE is ready. */
	while( RCC_GetFlagStatus( RCC_FLAG_HSERDY ) == RESET )
	{
	}

	/* 2 wait states required on the flash. */
	*( ( unsigned long * ) 0x40022000 ) = 0x02;

	/* HCLK = SYSCLK */
	RCC_HCLKConfig( RCC_SYSCLK_Div1 );
	
	/* PLLCLK = 8MHz * 9 = 72 MHz. */
	RCC_PLLConfig( RCC_PLLSource_HSE_Div1, RCC_PLLMul_9 );
	
	
	/* Enable PLL. */
	RCC_PLLCmd( ENABLE );

	/* Wait till PLL is ready. */
	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
	{
	}

	/* Select PLL as system clock source. */
	RCC_SYSCLKConfig( RCC_SYSCLKSource_PLLCLK );

	/* Wait till PLL is used as system clock source. */
	while( RCC_GetSYSCLKSource() != 0x08 )
	{
	}
	
	

	
	
	

	/* Configure HCLK clock as SysTick clock source. */
	SysTick_CLKSourceConfig( SysTick_CLKSource_HCLK );
#else

	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
#endif
	
	
	
	
	//prvSetupHardware();
	c++;
	xTaskCreate(run1, "Task1", 100, NULL, 1, NULL);
	c++;

	c++;
	xTaskCreate(run2, "Task2", 100, NULL, 1, NULL);
	c++;
	
	vTaskStartScheduler();
//	while(1)
//	{
//		c++;
//	}
	return 0;
}


