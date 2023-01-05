#include <stdio.h>

/* return 1 = little endian
          0 = Big Endian 
*/

int endianness(){
   int i = 1; 
   char *x = (char *) &i;
   
   return (*x);
   }
   
   int main()
   {
       endianness() ? printf("Little Endian\n") : printf("Big Endian\n");
       return 0;
   }
   
   /* Output on a Little Endian Machine - 
   
   Little Endian

   */
