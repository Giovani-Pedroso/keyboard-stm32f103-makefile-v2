#ifndef KEYBOARD_KEYBOARD_H_
#define KEYBOARD_KEYBOARD_H_
#include "FreeRTOS.h"
#include "main.h"

typedef struct{
	GPIO_TypeDef* port;
	uint16_t pin;
}Pins_t;

#define KEYBOARD_PRIORITY 5
#define KEYBOARD_STACK 100

void right_check_keys(void); 

#endif /* KEYBOARD_KEYBOARD_H_ */
