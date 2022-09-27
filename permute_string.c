#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
  char temp; 
  temp = *a; 
  *a = *b; 
  *b = temp;
  
  return;
}

void permute(char *str, int i, int j){
  int k;
  
  if(i == j){
    printf(" %s \n", str);
    return; 
  }
  else {
    for(k = i; k < j; k++){
      swap((str + k), (str + i));
      permute(str, i + 1, j);
      swap((str + k), (str + i));
    }
  }
  
  return;
}

int main(){
 
  char str[] = "abc";
  int len = strlen(str);
  
  permute(str, 0, len);
  
  return 0;
}
