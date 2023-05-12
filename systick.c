#include "declarations.h"

void initSystick(void) {
	NVIC_ST_CTRL_R = 0X00;
	NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;
	NVIC_ST_CURRENT_R = 0X00;
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE | NVIC_ST_CTRL_CLK_SRC ;
}

void delayInSeconds(int total) {
	int i;
	for (i=0; i < total; i++) {
		NVIC_ST_RELOAD_R = (16000000) - 1;
		NVIC_ST_CURRENT_R = 0X00;
		while ((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0x00){}
	}
}

void delay(int total) {
	int i;
	for (i=0; i < total; i++) {
		NVIC_ST_RELOAD_R = (16000) - 1;
		NVIC_ST_CURRENT_R = 0X00;
		while ((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0x00){}
	}
}
