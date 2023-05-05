#define declarations
#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

char currentGLL[50];
double  destLat, destLong, startLat, startLong,
        currentLat, currentLong, oldLat, oldLong,
        oldDist, sumOfDist;
bool firstTime, firstStep;

void PORTA_Init(void);			   	// initializes
void PORTB_Init(void);			   	// initializes
void PORTD_Init(void);			   	// initializes
void PORTE_Init(void);			   	// initializes
void PORTF_Init(void);			   	// initializes

void UART0_Init();
int UART0_READ_AVA(void);			// this function to see if fifo is full or not
char read_UART0(void);				//fn to read the input from GPS
void write_UART0(char y);			//fn to write char by char
char *Making_input_str(char *str);	// this function is making the input chars into string
void print_string(char *c);			//fn to print string

void systick_init();
void delay_IN_s(int total);

void getCoordinates (char * ptr);
double toDouble(char * s, int length);

void GettingCloserOrFarther(double destX, double destY, double currentX, double currentY);
void CalculateStepsTaken(double currentX, double currentY);
double distance(double x1,double x2,double y1,double y2);

