#include <stdio.h>

int powof2(unsigned int n){
  return (n && !(n & (n - 1)));
}
          
int main() {
  
  printf("8 is power of 2 = %s\n", powof2(8) ? "Yes" : "No");
  printf("6 is power of 2 = %s\n", powof2(6) ? "Yes" : "No");
  
  return 0;
}

/* Expected results:
8 is power of 2 = Yes
6 is power of 2 = No
*/
