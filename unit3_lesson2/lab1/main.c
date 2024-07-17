#include "uart.h"
char text[100]="learn_in_depth:Youssef";
char un_text[100];
int const cons_Name=4;
void main()
{
   uart_send_str(text);
  
}