#include <stdio.h>
#include<pthread.h>
#include <unistd.h>

#define LOOP_COUNT 5

void *myturn(void *var){
   
   for(int i = 0; i < LOOP_COUNT; i++){
        printf("\nMy Turn");
        sleep(1);
    }
    return NULL;
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
    pthread_create(&mythread, NULL, myturn, NULL); // Creats threads, pass pthread_t as an arg to get thread_id,
                                                   // Second param i.e. NULL is for thread attributes 
                                                   // myturn is the function pointer for the thread to execute. 
                                                   // the forth param NULL is to pass param to the function pointer, which we do not have in this example 
                                                   // hence NULL.
    yourturn();
    
    pthread_join(mythread, NULL);                  // Since main thread can finish early, and we want to wait for the thread to complete... using 
                                                   // pthread_join(). The first param is thread id, seconds param is NULL as we donot care about the 
                                                   // return value from the thread.
    
    return 0;
}
