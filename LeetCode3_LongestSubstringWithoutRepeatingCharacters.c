#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char *s) {
    int charIndexMap[256]; // Assuming ASCII characters

    memset(charIndexMap, -1, sizeof(charIndexMap));

    int start = 0;
    int maxLength = 0;

    for (int end = 0; s[end] != '\0'; ++end) {
        if (charIndexMap[s[end]] != -1 && charIndexMap[s[end]] >= start) {
            start = charIndexMap[s[end]] + 1;
        }

        charIndexMap[s[end]] = end;
        maxLength = (end - start + 1) > maxLength ? (end - start + 1) : maxLength;
    }

    return maxLength;
}

int main()
{                                                         
    printf(" maxlength = %d\n", lengthOfLongestSubstring("pwwkew"));
    printf(" maxlength = %d\n", lengthOfLongestSubstring("bbbb"));
    printf(" maxlength = %d\n", lengthOfLongestSubstring("abcabcbb"));
    printf(" maxlength = %d\n", lengthOfLongestSubstring("aabbbccccabcbb"));

    return 0;
}

/* Output:

 maxlength = 3
 maxlength = 1
 maxlength = 3
 maxlength = 3

*/
