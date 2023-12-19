#include <stdio.h>

typedef struct mystr{
    int a; 
    char b; 
    float c;
}mystr_t ;

#define offsetof(type, member)  ((size_t) (&(((type *) 0)->member)))

int main(){
    printf("offsetof a is = %lu\n", offsetof(mystr_t, a));
    printf("offsetof b is = %lu\n", offsetof(mystr_t, b));
    printf("offsetof c is = %lu\n", offsetof(mystr_t, c));
}

/* output 

offsetof a is = 0
offsetof b is = 4
offsetof c is = 8

*/
