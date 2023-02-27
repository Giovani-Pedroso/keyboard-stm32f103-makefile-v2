#include "MCP23017.h"
#include "main.h"
#include "stm32f1xx_hal_i2c.h"
#include <stdint.h>
/* I2C_HandleTypeDef hi2c1; */

// testing the mcp to blink and led
/**
         @brief initializes the mcp23017 for the keyboard
 */
void MCP23017_init(I2C_HandleTypeDef *i2c) {

  uint8_t pins_out = 0xE0;
  uint8_t pull_up_a = 0xff;
  uint8_t zero = 0x00;

  // config the pins in the port B as output except for the pins 7,6,5
  HAL_I2C_Mem_Write(i2c, MCP23017_ADDR, MCP23017_IODIRB, 1, &pins_out, 1, 1000);

  // config all the pins of the PORT A as input pull up
  HAL_I2C_Mem_Write(i2c, MCP23017_ADDR, MCP23017_GPPUA, 1, &pull_up_a, 1, 1000);

  // config the pins 7,6,5 of the port b as pull up
  HAL_I2C_Mem_Write(i2c, MCP23017_ADDR, MCP23017_GPPUB, 1, &pins_out, 1, 1000);

  // set all b pins to low
  HAL_I2C_Mem_Write(i2c, MCP23017_ADDR, MCP23017_OLATB, 1, &zero, 1, 1000);
}

/**
         @brief this function will put all pins of the port high except for the
   pins 7,6,5 and the other pin that the user will want
 */
void MCP23017_high_all_b_except(I2C_HandleTypeDef *i2c, uint8_t PIN) {
  // pins 0 to 5 high
  uint8_t pins = 0x1F;
  // set a pin to zero
  pins &= ~(1 << PIN);

  HAL_I2C_Mem_Write(i2c, MCP23017_ADDR, MCP23017_OLATB, 1, &pins, 1, 1000);
}

/**
         @brief return the logic value of a pin in the PORTA
         @param the i2c withc the mcp is connect
         @param the pin to be tested
 */
uint8_t MCP23017_read_pin_port_a(I2C_HandleTypeDef *i2c, uint8_t PIN) {
  uint8_t value = 0;

  HAL_I2C_Mem_Read(i2c, MCP23017_ADDR, MCP23017_GPIOA, 1, &value, 1, 1000);

  // when pressed the pins will be in the logic level 0
  return ~(value) & (1 << PIN);
}

/**
         @brief return the logic value of a pin in the PORTA
         @param the i2c withc the mcp is connect
 */
uint8_t MCP23017_read_encoder(I2C_HandleTypeDef *i2c){
  uint8_t value = 0;
	
  HAL_I2C_Mem_Read(i2c, MCP23017_ADDR, MCP23017_GPIOB, 1, &value, 1, 1000);

	//the encode is connect in the pins b1,b2(direction), b3 button
	//this will mask the the buttons, low LN means active
	return (~(value) & 0xE0) >> 5;
}
