#include "declarations.h"

extern char currentGLL[50];

void initUART1(void){
	SYSCTL_RCGCUART_R |= 0x02;  // Active UART1
	while ((SYSCTL_PRUART_R & 0x02)==0) {}

	UART1_CTL_R &= ~(0X01);    
	UART1_IBRD_R = 104; // Baud rate = 9600
	UART1_FBRD_R = 11;
	UART1_LCRH_R |= 0X070;//8 Bits , FIFOs , 1 stop bit , NO Parity bits
	UART1_CTL_R |= 0X201;
}

char read_UART1(void){ 
	while ((UART1_FR_R & 0x10) != 0);
	return (char)(UART1_DR_R & 0XFF);
}
void makeInputString(char *str){
	char input;
	int i;
	for (i = 0; i < 50; i++) {
		str[i] = '\0';
	}
	for (i = 0; i < 50; i++) { 
		input = read_UART1();
		
		str[i] = input;
		if ( input == '\n') break;
	}
	for (i = 0; i < 50; i++) { 
		input = read_UART1();
		if ( input == '\n') break;
	}
	str[49] = '\0';
}
