/* Create a function to return power of 2, 4 and 8 using bitwise operator*/

#include <stdio.h>
#include <stdint.h>

uint64_t pow2(uint8_t p)
{
    return (1 << p);
}

uint64_t pow4(uint8_t p)
{
    return (pow2(2 * p));
}

uint64_t pow8(uint8_t p)
{
    return (pow2(3 * p));
}

int main()
{
    printf("2^4 = %lu\n", pow2(4));
    printf("4^4 = %lu\n", pow4(4));
    printf("8^4 = %lu\n", pow8(4));

    printf("2^0 = %lu\n", pow2(0));
    printf("4^0 = %lu\n", pow4(0));
    printf("8^0 = %lu\n", pow8(0));
    
    printf("2^10 = %lu\n", pow2(10));
    printf("4^10 = %lu\n", pow4(10));
    printf("8^10 = %lu\n", pow8(10));
    
    return 0;
}

/* Output 

2^4 = 16
4^4 = 256
8^4 = 4096
2^0 = 1
4^0 = 1
8^0 = 1
2^10 = 1024
4^10 = 1048576
8^10 = 1073741824

*/
