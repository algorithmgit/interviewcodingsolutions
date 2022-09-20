/* given a sorted array, search for an element in the array using binary search. Implement an iterative solution. */ 


#include <stdio.h>

int main () {
 
  int arr[] = {3, 4, 6, 8, 9, 10, 12, 15, 18, 20};
  int x = 12; // the number to find 
  //int x = 1100; // the number to find 
  
  int left, right, mid; 
  
  left = 0;; 
  right = (sizeof(arr) / sizeof(int)) - 1; 
  
  printf("left = %d, right = %d\n", left, right);
  
  while(left <= right) { 
    mid = left + (right - left) / 2; 
    
    if (arr[mid] < x) 
      left = mid + 1 ; 
    else if (arr[mid] > x) 
      right = mid - 1;
    else if (arr[mid] == x) {
      printf("\nFound %d at index %d\n", x, mid); 
      break;
    }
  }
    
    if(arr[mid] != x) // did not find the element. 
      printf("\nDid not find the element x = %d, in the arr\n", x); 
      
  return 0;
}

