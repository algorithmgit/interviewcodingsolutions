/* Find the stack growth direction */

#include <stdio.h>

void stack_growth_direction (int *i){
  int j; 
  if (&j > i) {
    printf("Stack is growing upwards\n");
  }
  else { 
    printf("Stack is growing Downwards\n");
  }
}

int main(){
  int i; 
  stack_growth_direction(&i);
  return 0;
}


/* Output on gdb online C */ 
// Stack is growing Downwards
