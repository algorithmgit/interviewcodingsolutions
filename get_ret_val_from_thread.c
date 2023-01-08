/* Example program to show how to receive a value from a thread.
   in this example the thread allocates the memory for a var that is retured to main() by pthread_join(). The second param of pthread_join() takes 
   void ** as an input hence typecasting of int *var to (void *)&var. 
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // for sleep()
#include <stdlib.h>  // for malloc ()

#define LOOP_COUNT 20

void *myturn(void *var){

   int *var2 = (int *) malloc(sizeof(int));
   *var2 = LOOP_COUNT;
   
   for(int i = 0; i < LOOP_COUNT; i++){
        printf("\nMy Turn %d", *var2);
        (*var2)++;
        sleep(1);
    }
    return ((void *) var2);
}

void yourturn(){
    for(int i = 0; i < LOOP_COUNT; i++){
        printf("\nYour Turn");
        sleep(1);
    }
    return;
}

int main(){
    
    pthread_t mythread;
    int *var = NULL; 
    pthread_create(&mythread, NULL, myturn, NULL);
    yourturn();
    
    pthread_join(mythread, (void *) &var);
    
    printf("\nReceived var = %d\n", *var);
    
    return 0;
}
