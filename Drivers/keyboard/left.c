/*
 * keyboard.c
 *
 *  Created on: Oct 16, 2022
 *      Author: santana
 */
#include "FreeRTOS.h"
#include "main.h"
#include "rigth.h"
#include "ssd1306.h"
#include "usb_send.h"

#include "task.h"

const Pins_t cols[] = {
    {GPIOB, GPIO_PIN_12}, {GPIOB, GPIO_PIN_13}, {GPIOB, GPIO_PIN_14},
    {GPIOB, GPIO_PIN_15}, {GPIOB, GPIO_PIN_3},  {GPIOB, GPIO_PIN_4},

};

const Pins_t rows[] = {
    {GPIOA, GPIO_PIN_1}, {GPIOA, GPIO_PIN_0}, {GPIOA, GPIO_PIN_15},
    {GPIOA, GPIO_PIN_9}, {GPIOA, GPIO_PIN_8},
};
char test_chars[6] = {'0', '1', '2', '3', '4', '5'};

const uint8_t nRows = sizeof(rows) / sizeof(Pins_t);
const uint8_t nCols = sizeof(cols) / sizeof(Pins_t);

void right_check_keys() {
  /*
          ALL WORKING
          w - working, n - not working
          STM-board
          [w] [w] [w] [w] [w] [w]
          [w] [w] [w] [w] [w] [w]
          [w] [w] [w] [w] [w] [w]
          [w] [w] [w] [w] [w] [w]
          [w] [w] [w] [w] [w] [w]
   */
  // cols
  for (int i = 0; i < nCols; i++) {
    HAL_GPIO_WritePin(cols[i].port, cols[i].pin, GPIO_PIN_SET);
    // rows
    for (int j = nRows-1; j >=0; j--) {
      if (HAL_GPIO_ReadPin(rows[j].port, rows[j].pin)) {
        // send the command to the usb
        /* usb_sender_test('l', test_chars[i], test_chars[j]); */
        usb_send('l', j, i);
      }
    }
    HAL_GPIO_WritePin(cols[i].port, cols[i].pin, GPIO_PIN_RESET);
  }
}
