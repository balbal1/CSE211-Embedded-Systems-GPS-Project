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
void initPortF(void);

void initUART0(void);
void write_UART0(char y);
void printString(char *str);
void printStringln(char *str);
void printDouble(double n);

void initUART1(void);
char read_UART1(void);
void makeInputString(char *str);

void initSystick(void);
void delayInSeconds(int total);
void delay(int total);

void getCoordinates (char * ptr);
double fixCoordinate (double coordinate);

void chooseLedColor(double destX, double destY, double currentX, double currentY);
void calculateStepsTaken(double oldX, double oldY, double currentX, double currentY);
double distance(double x1,double x2,double y1,double y2);
void ledON(int color);
void ledOFF(void);
void serialPrint(void);
