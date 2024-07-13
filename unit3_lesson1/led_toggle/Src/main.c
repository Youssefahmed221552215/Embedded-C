/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Youssef Ahmed
 * @brief          : Main program body
 *****************
 */

#include "stdint.h"
#define RCC 0x40021000
#define GPIO_PORTA 0x40010800
#define APB2ENR  *(volatile uint32_t *)(RCC+0x18)
#define CRH *(volatile uint32_t *)(GPIO_PORTA+0x04)
#define ODR *(volatile uint32_t *)(GPIO_PORTA+0x0C)
int main()
{
	int i;
	APB2ENR|=(1<<2);
	CRH&=0xFF0FFFFF;
	CRH|=0x00200000;
	while(1){
		ODR|=(1<<13);
		for(i=0;i<1000;i++);
			ODR&=~(1<<13);
		for(i=0;i<1000;i++);

	}







}

