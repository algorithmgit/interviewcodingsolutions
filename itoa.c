#include <stdio.h>

void reverse(char s[], int length) {
    int i = 0;
    int j = length - 1;
    
    char temp = '\0';
    while (i < j) {
        temp = s[j];
        s[j] = s[i];
        s[i++] = temp;
        j--;
    }
}

char * myitoa(int n, char *str, int base) {
    int reminder = 0;
    int isNegative = 0;
    int i = 0;
    
    // Special case handling of 0
    if(n == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    
    // if the number is negative
    if(n < 0) {
        isNegative = 1;
        n = -n;
    }
    
    while(n) {
        reminder = n % base;
        str[i++] = (reminder > 9) ? (reminder - 10) + 'a' : reminder + '0';
        n /= base;
    }
    
    if(isNegative) str[i++] = '-';
    str[i] = '\0';
    
    reverse(str, i);
    
    return str;
}

int main() {
    char buf[10];
    printf("num string is %s\n", myitoa(1234, buf, 10));
}
