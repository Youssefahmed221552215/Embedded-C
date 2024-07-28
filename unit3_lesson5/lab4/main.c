#include "stdint.h"
#include <stdlib.h>
typedef volatile  unsigned int vint32_t;
#define RCC_BASE 0x40021000
#define portA_BASE 0x40010800
#define RCC_ABP2ENR *(volatile uint32_t *) (RCC_BASE+0x18)
#define GPIOA_CRH *(volatile uint32_t *) (portA_BASE+0x04)
#define GPIOA_ODR *(volatile uint32_t *) (portA_BASE+0x0C)
#define heap_width 100
unsigned char g_variables[3]={1,2,3};
unsigned char const  const_variables[3]={1,2,3};
volatile unsigned char bss_var[3];
void* _sbrk(int incr)
{
	static unsigned char* heap_ptr=NULL;
	unsigned char* prev_heap_ptr=NULL;
	extern unsigned int _E_bss;
	extern unsigned int _heap_END;
	if(heap_ptr==NULL)
		heap_ptr=(unsigned char*)&_E_bss;
	prev_heap_ptr=heap_ptr;
	if((unsigned char*)(heap_ptr+incr)>(unsigned char*)(&_heap_END))
	return (void*) NULL;
	heap_ptr+=incr;
	return (void*) prev_heap_ptr;
	

}

int main(void)
{
	int* p =(int* ) malloc(4);
    free(p);
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