#include "left.h"
#include "FreeRTOS.h"
#include "MCP23017.h"
#include "main.h"
#include "portmacro.h"
#include "rigth.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_i2c.h"
#include "task.h"
#include "usb_send.h"
#include <stdint.h>
#include "check_keys.h"

extern I2C_HandleTypeDef hi2c1;

void check_keys_task(void *vparams) {

  /* I2C_HandleTypeDef *i2c = (I2C_HandleTypeDef *)vparams; */

  MCP23017_init(&hi2c1);

  // Additional configuration to use the pins pb3 and pb4
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  AFIO->MAPR = AFIO_MAPR_SWJ_CFG_1;

  while (1) {
    left_check_keys();
    right_check_keys();
		vTaskDelay(10/ portTICK_PERIOD_MS);
  }
}

void check_keys_task_init() {
  xTaskCreate(&check_keys_task, "check_keys_task",
              CHECK_KEYS_SIZE, NULL,
              CHECK_KEYS_PRIORITY, NULL);
}
