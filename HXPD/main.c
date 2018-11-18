#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "src/I2C.h"


int main(void) {
    
  i2c_status_t i2c_status;
  i2c_status = i2c_UNKNOWN;
  I2C_InitPort1();
  

#define LED4_ON_L (0x16)
#define LED4_ON_H (0x17)
#define LED4_OFF_L (0x18)
#define LED4_OFF_H (0x19)
  //LED4_ON_H = Eh; LED4_ON_L = 65h 
  //LED4_OFF_H = Ch; LED4_OFF_L = CBh
  uint8_t regData = 0x00;
#define PCA_9685_ADDR 0x40
#define MODE1 0x00
  
  I2C_WriteBytes(PCA_9685_ADDR, MODE1, 0x55,WRITE);   
  I2C_Read(PCA_9685_ADDR, MODE1, &regData);
 
  
  i2c_status = I2C_WriteBytes(0x40,LED4_ON_L,0x0E, WRITE);
  i2c_status = I2C_WriteBytes(0x40,LED4_ON_H,0x65, WRITE);
  i2c_status = I2C_WriteBytes(0x40,LED4_OFF_L,0x0C, WRITE);
  i2c_status = I2C_WriteBytes(0x40,LED4_OFF_H,0xCB, WRITE);

  while(1){

  }

return 0;
}