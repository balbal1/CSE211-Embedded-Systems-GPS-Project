#define declarations
#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define red  0x02
#define green  0x08
#define yellow  0x0C

char currentGLL[50];
double  destLat, destLong, startLat, startLong,
        currentLat, currentLong, oldLat, oldLong,
        oldDist, sumOfDist;
bool firstTime, firstStep;

void initPortA();
void initPortB();
void initPortD();
void initPortE();
void initPortF();

void UART0_Init();
char read_UART0();					//fn to read the input from GPS
void write_UART0(char y);			//fn to write char by char
void Making_input_str(char *str);	// this function is making the input chars into string
void print_string(char *c);			//fn to print string

void initSystick();
void delayInSeconds(int total);
void delay(int total);

void getCoordinates (char * ptr);
double toDouble(char * s, int length);

void GettingCloserOrFarther(double destX, double destY, double currentX, double currentY);
void CalculateStepsTaken(double currentX, double currentY);
double distance(double x1,double x2,double y1,double y2);
void ledON(int color);
void ledOFF();

