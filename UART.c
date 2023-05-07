#include "declarations.h"

char currentGLL[50] = {'\0'};

/*int main(){  
	initPortA();
	initUART0();
	while(1) {
		MakeInputString(currentGLL);
		print_string(currentGLL);
	}
}*/

//intialization	FOR UART_0
//U0_RX PIN A0 for reading data 
//U0_TX PIN A1 for writing data
void initUART0(){
	SYSCTL_RCGCUART_R |= 0x01;  // Active UART0
	
	//SYSCTL_RCGCGPIO_R |= 0X01; // ACTIVE port A
	
	UART0_CTL_R &= ~(0X01);    
	UART0_IBRD_R = 104; // Baud rate = 9600
	UART0_FBRD_R = 11;
	UART0_LCRH_R |= 0X070;//8 Bits , FIFOs , 1 stop bit , NO Parity bits
	UART0_CTL_R |= 0X201;
	
	//GPIO_PORTA_AFSEL_R |= 0X03;//Enable alternative fn in PA0-1
	//GPIO_PORTA_DEN_R |= 0X03; 
	//GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0XFFFFFF00) + 0X011; //Making p0-1 UART
	//GPIO_PORTA_AMSEL_R &= ~(0X03);
}

char read_UART0(void){ 
	while ((UART0_FR_R & 0x10) != 0);
	return (char)(UART0_DR_R & 0XFF);
}

void write_UART0(char y){
	while ((UART0_FR_R & 0X20) != 0);
	UART0_DR_R = y;
}

void MakeInputString(char *str){
	char input;
	int i;
	for (i = 0; i < 50; i++) {
		str[i] = '\0'; //turning the string into null to use it again
	}
	for (i = 0; i < 50; i++) { 
		input = read_UART0();
		str[i] = input;
		if ( input == '*') break;
	}
} 

void print_string(char *c){
	while (*c) {
		write_UART0(*c);
		c++;
	}
	write_UART0('\n');
}
