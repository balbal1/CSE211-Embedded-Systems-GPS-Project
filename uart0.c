#include "declarations.h"

void initUART0 (void) {
	SYSCTL_RCGCUART_R |= 0x0001;
	
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)|0x00000011;
	UART0_CTL_R &= ~0x0001;
	
	UART0_IBRD_R = 104;
	UART0_FBRD_R = 11;
	UART0_LCRH_R = 0x0070;
	UART0_CTL_R = 0x0301;
}

void write_UART0(char y){
	while ((UART0_FR_R & 0X20) != 0);
	UART0_DR_R = y;
}

void printString(char *str){
	while (*str) {
		write_UART0(*str);
		c++;
	}
}
void printStringln(char *str){
	printString(str);
	write_UART0('\r');
	write_UART0('\n');
}
void printDouble(double n){
	char string[11];
	sprintf(string, "%f", n);
	printStringln(string);
}
