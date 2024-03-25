#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int memcpy1(void *dst, void *source, size_t length) {
    int count = length;
    char *dest = (char *) dst; 
    const char *src = (char *) source;
    
    if(dest == NULL || src == NULL) return -1 ;
    
    if (dst < src){
        while(length --){
            *dest++ = *src++;
        }
    } else {
        dest += length; 
        src += length;
        while(length --){
            *--dest = *--src;
        }
    }
    
    return count;
}

int memcpy2(void *dst, void *source, size_t length) {
    int count = length;
    int *dest = (int *) dst; 
    const int *src = (int *) source;
    
    if(dest == NULL || src == NULL) return -1 ;
    
    if(length < 4)
        memcpy1(dst, source, length);
        
    if (dst < src){
        while(length){
            *dest++ = *src++;
            length -= sizeof(int);
            if(length < 4){
                memcpy1(dest+(count - length), src + (count - length), length);
                break;
            }       
        }
    } else {
        dest += length; 
        src += length;
        while(length){
            *--dest = *--src;
            length -= sizeof(int);
            if(length < 4){
                memcpy1(dest+length , src+length , length);
                break;
            }               
        }
    }
    
    return count;
}

int main() {

    return 0;
}
