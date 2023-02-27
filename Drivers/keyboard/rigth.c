#include "rigth.h"
#include "FreeRTOS.h"
#include "MCP23017.h"
#include "left.h"
#include "main.h"
#include "portmacro.h"
#include "ssd1306.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_i2c.h"
#include "task.h"
#include "usb_send.h"
#include <stdint.h>

extern I2C_HandleTypeDef hi2c1;
char test_carh_keft[8] = {'0','1','2','3','4','5','6','7'};
void left_check_keys(I2C_HandleTypeDef *i2c) {
  /*
          TWO KEYS ARE NOT WORKING
          w - working, n - not working
                                        Display board
          [w] [w] [X] [w] [w] [w]
          [w] [w] [w] [w] [w] [w]
          [w] [w] [w] [w] [w] [w]
          [w] [w] [w] [w] [w] [n]
          [w] [w] [w] [w] [w] [Y]
                                        X - is always pressed
                                        Y - Is not registering press
   */
  // Rows - ok
  for (int j = 4; j >=0; j--) {
    MCP23017_high_all_b_except(&hi2c1, j);
    for (int i = 0; i < 6; i++) {
      if (MCP23017_read_pin_port_a(&hi2c1, i)) {
        /* usb_sender_test('r', test_carh_keft[i], test_carh_keft[j]); */
        /* usb_sender_test('r', test_carh_keft[i], test_carh_keft[j]); */
        usb_send('r', j, i);
      }
    }
  }
}
