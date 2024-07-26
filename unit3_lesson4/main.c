#define SYSTL_RCGC2_R  (*(volatile unsigned int*)(0x400FE108))
#define GPIO_PORTF (*(volatile unsigned int*)(0x40025000))
#define GPIO_PORTF_DATA_R  (*(volatile unsigned int*)(GPIO_PORTF+0x3FC))
#define GPIO_PORTF_DIR_R  (*(volatile unsigned int*)(GPIO_PORTF+0x400))
#define GPIO_PORTF_DEN_R (*(volatile unsigned int*)(GPIO_PORTF+0x51C))
void main()
{
	volatile unsigned long counter;
	SYSTL_RCGC2_R=0x00000020;
	for(counter=0;counter<200;counter++);
	GPIO_PORTF_DIR_R |=1<<3;
	GPIO_PORTF_DEN_R |=1<<3;
	while(1)
	{
	GPIO_PORTF_DATA_R |=1<<3;
	for(counter=0;counter<200000;counter++);
	GPIO_PORTF_DATA_R &=~(1<<3);
	for(counter=0;counter<20000;counter++);	
    }
return 0;
}