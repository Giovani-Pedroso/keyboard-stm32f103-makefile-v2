#ifndef MCP23017_H
#define MCP23017_H

#include <stdint.h>
#include "main.h"
#include "stm32f1xx_hal_i2c.h"
#define MCP23017_ADDR (0X20<<1)

// Input Output DIrection Register A/B
//0 = Output - 1=Input
//reset value = 0xff
#define MCP23017_IODIRA 0x00
#define MCP23017_IODIRB 0x01

//INPUT POLARITY REGISTER
#define MCP23017_IPOLA 0x02
#define MCP23017_IPOLB 0x03

//NTERRUPT-ON-CHANGE CONTROL REGISTER
#define MCP23017_GPINTENA 0x04
#define MCP23017_GPINTENB 0x05

//DEFAULT COMPARE REGISTER FOR INTERRUPT-ON-CHANGE
#define MCP23017_DEFVALA 0x06
#define MCP23017_DEFVALB 0x07

//INTERRUPT CONTROL REGISTER
#define MCP23017_INTCONA 0x08
#define MCP23017_INTCONB 0x09

//I/O EXPANDER CONFIGURATION REGISTER 
#define MCP23017_IOCON_1 0x0A
#define MCP23017_IOCON_2 0x0B

//PULL-UP RESISTOR CONFIGURATION REGISTER
#define MCP23017_GPPUA 0x0C
#define MCP23017_GPPUB 0x0D

//INTERRUPT FLAG REGISTER (
#define MCP23017_INTFA 0x0E
#define MCP23017_INTFB 0x0F

//INTERRUPT CAPTURED VALUE FOR PORT REGISTER 
#define MCP23017_INTCAPA 0x10
#define MCP23017_INTCAPB 0x11

//Data port- register the level of the pin (input)
#define MCP23017_GPIOA 0x12
#define MCP23017_GPIOB 0x13

//Set the outpu value
#define MCP23017_OLATA 0x14
#define MCP23017_OLATB 0x15

void MCP23017_init(I2C_HandleTypeDef *i2c);
void MCP23017_write_pin(I2C_HandleTypeDef *i2c, uint8_t PORT, uint8_t PIN);
void MCP23017_high_all_b_except(I2C_HandleTypeDef *i2c, uint8_t PIN);
uint8_t MCP23017_read_pin_port_a(I2C_HandleTypeDef *i2c, uint8_t PIN);
uint8_t MCP23017_read_encoder(I2C_HandleTypeDef *i2c);

#endif
