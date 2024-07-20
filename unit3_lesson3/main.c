#include "stdint.h"
#define RCC_BASE 0x40021000
#define portA_BASE 0x40010800
#define RCC_ABP2ENR *(volatile uint32_t *) (RCC_BASE+0x18)
#define GPIOA_CRH *(volatile uint32_t *) (portA_BASE+0x04)
#define GPIOA_ODR *(volatile uint32_t *) (portA_BASE+0x0C)
unsigned char g_variables[3]={1,2,3};
unsigned char const const_variables[3]={1,2,3};

int main(void)
{
	RCC_ABP2ENR |=1<<2;
	GPIOA_CRH &=0xff0fffff;
	GPIOA_CRH |=0x00200000;
	while(1)
	{
		GPIOA_ODR |=1<<13;
		for(int i=0;i<5000;i++);
		GPIOA_ODR &=~1<<13;
		for(int i=0;i<5000;i++);
	}



}