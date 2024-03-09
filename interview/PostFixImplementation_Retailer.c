#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_MAX_STR_SIZE 32

typedef enum {
  STATUS_SUCCESS,
  STATUS_INVALID,
  STATUS_DIVIDE_BY_ZERO
} FuncStatus_t;

typedef struct {
    int top;
    int nums[NUM_MAX_STR_SIZE]; /* we will store only ints in the stack */
} stack_t;

void init_stack(stack_t *stack){
    stack->top = -1; /* Indicating that the stack is empty */
}

int is_empty(stack_t *stack){
    return (stack->top == -1);   /* if top == -1, the stack is empty */
}

int is_full(stack_t *stack){
    return (stack->top == NUM_MAX_STR_SIZE -1);
}

int num_elements_stack(stack_t *stack){
    return stack->top + 1; /* index starts with 0 */
}

void push (stack_t *stack, int val){
    if(is_full(stack)){
        //printf(""Stack Overflow\n"");
        exit(EXIT_FAILURE);
    }
    stack->nums[++stack->top] = val;
}

int pop (stack_t *stack){
    if(is_empty(stack)){
        exit(EXIT_FAILURE);
    }
    return stack->nums[stack->top--];
}      


FuncStatus_t evaluatePostfix(const size_t postfix_size, const char* postfix[], int32_t *result)  {
    stack_t stack;
    init_stack(&stack);

    for(int i = 0; i < postfix_size; i++){
        if((isdigit(postfix[i][0])) || ((postfix[i][0] == '-') && (isdigit(postfix[i][1])))){
            push(&stack, atoi(postfix[i]));
        }
        else {
            if(num_elements_stack(&stack) < 2){
                return STATUS_INVALID;
            }

            int op2 = pop(&stack);
            int op1 = pop(&stack);

            switch (postfix[i][0]){
                case '+':
                    push(&stack, op1 + op2);
                    break;
                case '-':
                    push(&stack, op1 - op2);
                    break;
                case '*':
                    push(&stack, op1 * op2);
                    break;
                case '/':
                    if(op2 == 0){
                        return STATUS_DIVIDE_BY_ZERO;
                    }
                    push(&stack, op1 / op2);
                    break;
                default:
                    return STATUS_INVALID;
            }
        }
    }

    if (is_empty(&stack) || num_elements_stack(&stack) != 1) {
        return STATUS_INVALID;
    }

    if (result != NULL) {
        *result = pop(&stack);
    }

    return STATUS_SUCCESS;
}


/* 
  Explain the logic. 
   Run Time complexity = O(n)
   Space Complexity = O(n)? 
*/
