/* The EE comes back to you after prototyping and says that due to a manufacturing issue, the region of memory that your LED i/o resides 
in cannot be read from. It's write-only. Modify your function to account for this change. Assume that on boot the register is 0. */

#include <atdio.h>
#define LED_ADDRESS 0x1234 

uint8_t toggle_led(uint8_t ledposition){
  static uint8_t LED_REG_VAL = 0; // on boot the register is zero
  
  LED_REG_VAL = LED_REG_VAL ^ (1 << ledposition);
  (*(volatile uint8_t *)LED_ADDRESS) = LED_REG_VAL;
  
  return (LED_REG_VAL);
}

int main(){
 int reg_val = toggle_led(2); 
  
 printf("LED register val = %x\n", reg_val);
}
