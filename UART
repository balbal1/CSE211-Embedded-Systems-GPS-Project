//intialization	FOR UART_0
//U0_RX PIN A0 for reading data 
//U0_TX PIN A1 for writing data
void UART0_Init(){
	SYSCTL_RCGCUART_R |= 0x01;  // Active UART0
	SYSCTL_RCGCGPIO_R |= 0X01; // ACTIVE port A
  UART0_CTL_R &= ~(0X01);    
	UART0_IBRD_R = 104; // Baud rate = 9600
	UART0_FBRD_R = 11;
	UART0_LCRH_R |= 0X070;//8 Bits , FIFOs , 1 stop bit , NO Parity bits
	UART0_CTL_R |= 0X01;
	GPIO_PORTA_AFSEL_R |= 0X03;//Enable alternative fn in PA0-1
  GPIO_PORTA_DEN_R |= 0X03; 
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0XFFFFFF00) + 0X011; //Making p0-1 UART
	GPIO_PORTA_AMSEL_R &= ~(0X03);
}
//----------------------------------------------------------------------//
int UART0_READ_AVA(void);// this function to see if fifo is full or not 
char read_UART0(void);//fn to read the input from GPS
void write_UART0(char y);//fn to write char by char
char *Making_input_str(char *str);// this function is making the input chars into string
void print_string(char *c);//fn to print string 
//----------------------------------------------------------------------//
int main(){  
	char str[100]={0};
	UART0_Init();
  while(1)
   { int i;
		 print_string(Making_input_str(str));
		 for (i = 0; i < 100; i++)
		   {
				 str[i] = 0;//turning the string into zeros to use it again
		   }
		 }
}	
//----------------------------------------------------------------------//
int UART0_READ_AVA(void){
  return(((UART0_FR_R & 0X10)==0X10)?0:1);
}

char read_UART0(void){ 
	while (UART0_READ_AVA() != 1);
	return(UART0_DR_R & 0X0FF);
}


void write_UART0(char y){
	while ((UART0_FR_R & 0X20) != 0);
	UART0_DR_R = y;
}
//...........................
char *Making_input_str(char *str){
	char input;
	int i;
	for (i = 0; i < 100; i++)
	{ 
	  input = read_UART0();
	  if ( input == '\r') break;
		str[i] = input;
		}
	return(str);
} 
//...........................
void print_string(char *c){
	while (*c)
	{
		write_UART0(*c);
		c++;
	}
	 write_UART0('\n');
}
