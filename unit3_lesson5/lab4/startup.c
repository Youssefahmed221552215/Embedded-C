// startup.c 
// Eng:youssef
#include <stdint.h>
void Reset_Handler(void);
extern int main(void);
void Defult_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__ ((weak,alias ("Defult_Handler")));;
void H_fault_Handler(void) __attribute__ ((weak, alias ("Defult_Handler")));;
void MM_Fault_Handler(void) __attribute__ ((weak, alias ("Defult_Handler")));;
void Bus_Fault(void) __attribute__ ((weak, alias ("Defult_Handler")));;
void Usage_Fault_Handler(void) __attribute__ ((weak, alias ("Defult_Handler")));;
extern unsigned int _stack_top;
uint32_t vectors[] __attribute__((section(".vectors")))={
(uint32_t)&_stack_top,
(uint32_t)&Reset_Handler,
(uint32_t)&NMI_Handler,
(uint32_t)&H_fault_Handler,
(uint32_t)&MM_Fault_Handler,
(uint32_t)&Bus_Fault,
(uint32_t)&Usage_Fault_Handler
} ;
extern unsigned int _E_text ;
extern unsigned int _S_DATA  ;
extern unsigned int _E_DATA  ;
extern unsigned int _S_bss  ;
extern unsigned int _E_bss  ;

void Reset_Handler(void)
{
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* p_src =(unsigned char*)&_E_text ;
	unsigned char* p_dst =(unsigned char*)&_S_DATA ;
	for(int i=0 ;i<DATA_size;i++)
	{
		(*(unsigned char*)p_dst++)=(*(unsigned char*)p_src++);

	}
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	 p_dst =(unsigned char*)&_S_bss ;
	for(int i=0 ;i<bss_size;i++)
	{
		(*(unsigned char*)p_dst++)=(unsigned char)0;

	}

	main();

}