/* Implement Stack
   What would you use to hold the data? (Array/LinkedList...?) 
   Why would you use Array?
   Why would you use LinkedList?
   What would you use in an embedded device?
   Benefits of fix size array over linkedlist?
   What are the disadvantages?
  */
   
#include <iostream>

#define MAX_SIZE 2

class Stack {
    public:
    Stack() { top = -1; }
    void push(uint16_t data)
    {
        //printf("push 1: top = %d\n", top);
        if(is_full()) return;
        //printf("push 2: top = %d\n", top);
        top++; 
        arr[top] = data;
        //printf("push 3: top = %d, arr[top] = %d\n", top, arr[top]);
    }
    
    uint16_t pop(){
        if(is_empty()) return 0;
        
        uint16_t temp = arr[top];
        top --;
        return temp;
    }
    
    int size(){
        return top + 1;
    }
    
    bool is_empty(){
        if (top == -1)
            return true;
        
        return false;
    }
    
    bool is_full()
    {
        if (top >= MAX_SIZE - 1)
            return true; 
        
        return false;
    }
    
    uint16_t peek(){
        if (is_empty()) return 0;
        return arr[top];
    }
    
    void print(){
        if (!is_empty()) {
            for (int i = top; i >=0; i--){
                printf("%d \n", arr[i]);
            }
            printf("\n");
        }
    }
    
    private:
    uint16_t arr[MAX_SIZE];
    int8_t top; 
    
};

int main()
{
    Stack s;
    
    // Test case 1:
    s.push(1); 
    s.push(2);
    
    s.print();
 
    printf("num elements in the stack = %d\n", s.size()); 
    
    // Test case 1A:
    s.push(3); 
    s.print();
 
    printf("num elements in the stack = %d\n", s.size()); 
    
    // Test Case 2:
    s.pop(); 
    printf("num elements in the stack = %d\n", s.size()); 
    
    // Test Case 2A:
    s.pop();
    s.pop();
    s.pop();
    printf("num elements in the stack = %d\n", s.size()); 
    
    
    return 0;
}

/* 

 Test Case 1 : Test we can add elements into the stack; Print the start for verification
        1 A) Push when full
 Test Case 2 : Pop N elements from the Stack, and verify that N elemnets have been poped. 
        2 A) Pop when Empty 

*/

/* Output : 
2 
1 

num elements in the stack = 2
2 
1 

num elements in the stack = 2
num elements in the stack = 1
num elements in the stack = 0
*/ 
