/*
Check if binary representation of a number is palindrome or not

For example, 101, 11, 11011, 1001001 are palindromes. 100, 110, 1011, etc., are not palindromes.

      v  
  1 1 0 1 1
      ^  
    
    int i = 5; 
    
    num = 1 0 1    
    rev = 0 
*/ 

binaryPalindron(int32_t num){
    
    int32_t innum = num; 
    int32_t rev = 0;
    
    while(num > 0){
        rev = ( rev << 1) | (num &1); 
        num >>= 1;
    }
    
    return rev == innum; 
}

    
    bool binaryPalindrom(int32_t num){ // 5 
        int var = sizeof(int) * 8;
        char binStr[var]; 
        int idx = 0; 
        
        binStr = recalloc(binStr, size); 
                                  
        while(num > 0){    
            binStr[idx++] = (num & 1) + '0';  // idx = 0 , 101 & 1  => 0 = '1' , '1' '0', '1' '0' '1' 
            num >> 1; // 10 
        }
        binStr[idx] = '\0'; // '1' '0' '1' '\0'
        
        int len = strlen(binStr); 
        for (int i = 0; i < len / 2; i++){
            if (binStr[i] != binStr[len - 1 - i])
                return false
        }
        return true;
    }

    int main ()
    {
        int i = 5;
        printf("%s\n", binaryPlaindrom(i) ? "Yes" : "No");

      return 0;
    }
        
        
        
