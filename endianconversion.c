#include <stdio.h>

unsigned int endianconversion(unsigned int data) {
    unsigned int temp =  ( data >> 24) |   //MSB to LSB
                          ((data & 0x00FF0000) >> 8) | //
                          ((data & 0x0000FF00) << 8)  | 
                          (data << 24) ;  
    return (temp);
}

int main() {
  unsigned int number = 0x12345678;
  printf("%X conversion to => %X\n", number, endianconversion(number));
}

  
