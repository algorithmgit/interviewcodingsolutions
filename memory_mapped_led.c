/* Given an 16-bit MCU with LEDS mapped to each bit of a memory-mapped register i/o at address 0x1234. 
Write a function that takes, as an input, the LED position and toggles the LED at that given position in this memory-mapped register.*/

#include <stdio.h>

#define LED_ADD 0x1234
void toggle_led(uint8_t ledposition){
  (*(volatile uint16_t *)LED_ADD) ^= (1 << ledposition);
}

int main(){
  //toggle LED, represented by position 2.
  toggled_led(2);
}
