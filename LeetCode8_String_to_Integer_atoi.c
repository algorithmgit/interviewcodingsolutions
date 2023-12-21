/* String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char* s) {
  // NULL Pointer check 
  if (!s) return INT_MAX; 
  
  int result = 0;
  int i = 0, sign = 1, digit = 0;
  
  // Skip all white spaces 
  while(s[i] == ' ') i++;

  // Sign checks
  if(s[i] == '-') { sign = -1;i++;}
  else if(s[i] == '+') { sign = 1;i++;}
  
  while((s[i] != '\0') && isdigit(s[i])){
    digit = s[i] - '0';
    
    if((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10))
        return (sign == -1 ? INT_MIN : INT_MAX);
      
    result = 10 * result + digit;
    i++;
  }

  return result * sign;    
}

int main()
{                
    char *str = NULL;                                         
    printf(" maxlength = %d\n", myAtoi("0042"));
    printf(" maxlength = %d\n", myAtoi("-4200 abc"));
    printf(" maxlength = %d\n", myAtoi("4193"));
    printf(" maxlength = %d\n", myAtoi("abc"));
    printf(" maxlength = %d\n", myAtoi(""));
    printf(" maxlength = %d\n", myAtoi(str));
    printf(" maxlength = %d\n", myAtoi("1234"));
    printf(" maxlength = %d\n", myAtoi("Words are 987"));
    printf(" maxlength = %d\n", myAtoi("4193 with words")); 
    printf(" maxlength = %d\n", myAtoi("3.14159"));
    printf(" maxlength = %d\n", myAtoi("-+12"));
    printf(" maxlength = %d\n", myAtoi("+1"));

    return 0;
}

/* Output:
 maxlength = 42
 maxlength = -4200
 maxlength = 4193
 maxlength = 0
 maxlength = 0
 maxlength = 2147483647
 maxlength = 1234
 maxlength = 0
 maxlength = 4193
 maxlength = 3
 maxlength = 0
 maxlength = 1
*/
