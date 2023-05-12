#include "declarations.h"

extern char currentGLL[50];
extern char arr1[11];
extern char arr2[12];

void initUART0 (void) {
	SYSCTL_RCGCUART_R |= 0x0001;
	
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)|0x00000011;
	UART0_CTL_R &= ~0x0001;
	
	UART0_IBRD_R = 104;
	UART0_FBRD_R = 11;
	UART0_LCRH_R = 0x0070;
	UART0_CTL_R = 0x0301;
}

void initUART1(void){
	SYSCTL_RCGCUART_R |= 0x02;  // Active UART1
	while ((SYSCTL_PRUART_R & 0x02)==0) {}

	UART1_CTL_R &= ~(0X01);    
	UART1_IBRD_R = 104; // Baud rate = 9600
	UART1_FBRD_R = 11;
	UART1_LCRH_R |= 0X070;//8 Bits , FIFOs , 1 stop bit , NO Parity bits
	UART1_CTL_R |= 0X201;
}


void write_UART0(char y){
	while ((UART0_FR_R & 0X20) != 0);
	UART0_DR_R = y;
}
void printStringln(char *c){
	while (*c) {
		write_UART0(*c);
		c++;
	}
	write_UART0('\r');
	write_UART0('\n');
}
void printString(char *c){
	while (*c) {
		write_UART0(*c);
		c++;
	}
}
void printDouble(double n){
	char string[11];
	sprintf(string, "%f", n);
	printStringln(string);
}

char read_UART1(void){ 
	while ((UART1_FR_R & 0x10) != 0);
	return (char)(UART1_DR_R & 0XFF);
}
void makeInputString(char *str){
	char input;
	int i;
	for (i = 0; i < 50; i++) {
		str[i] = '\0'; //turning the string into null to use it again
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
