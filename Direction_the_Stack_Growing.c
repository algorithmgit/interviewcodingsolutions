/* Find the stack growth direction */

#include <stdio.h>

void fun (int *i){
  int j; 
  if (&j > i) {
    printf("Stack is gowing upwards\n");
  }
  else { 
    printf("Stack is gowing Downwards\n");
  }
}

int main(){
  int i; 
  fun(&i);
  return 0;
}

/* Output on gdb online C */ 
// Stack is gowing Downwards
