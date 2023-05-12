#define declarations
#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define red  0x02
#define green  0x08
#define yellow  0x0A

void initPortA(void);
void initPortB(void);
void initPortD(void);
void initPortE(void);
void initPortF(void);

void initUART0(void);
void write_UART0(char y);			//fn to write char by char
void printString(char *c);			//fn to print string
void printStringln(char *c);
void printDouble(double n);

void initUART1(void);
char read_UART1(void);					//fn to read the input from GPS
void makeInputString(char *str);	// this function is making the input chars into string

void initSystick(void);
void delayInSeconds(int total);
void delay(int total);

void getCoordinates (char * ptr);

void GettingCloserOrFarther(double destX, double destY, double currentX, double currentY);
void CalculateStepsTaken(double currentX, double currentY);
double distance(double x1,double x2,double y1,double y2);
void ledON(int color);
void ledOFF(void);
double fixCoordinate (double coordinate);

