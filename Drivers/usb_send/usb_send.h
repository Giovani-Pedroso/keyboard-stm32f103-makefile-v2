#ifndef USB_SEND_USB_SENDER_H_
#define USB_SEND_USB_SENDER_H_
#include "FreeRTOS.h"
#include <stdint.h>
#include "queue.h"

#define USB_SEND_STACK_SIZE 100
#define USB_SEND_PRIORITY 10
#define USB_SEND_QUEUE_LEN 4

typedef struct{
	uint8_t modifier_key;//shit, alt, controll
	uint8_t reserved;// do not assign any value here
	uint8_t keycode_1;//the code for the first key;
	uint8_t keycode_2;
	uint8_t keycode_3;
	uint8_t keycode_4;
	uint8_t keycode_5;
	uint8_t keycode_6;
} keyboard_command_t;

/* QueueHandle_t usb_send_queue; */

/*
 * @brief 	-For now I and sending the commands to the display ole
 * @parms 	-the struct to the keyboard command
 */
void usb_sender_send_comand_test(keyboard_command_t command);
void usb_sender_test(char keyboarSide, char column, char row);
void usb_send(char keyboarSide, uint8_t column, uint8_t row);
void usb_send_task_init();
void usb_send_task(void * vParams);
#endif /* USB_SEND_USB_SENDER_H_ */
