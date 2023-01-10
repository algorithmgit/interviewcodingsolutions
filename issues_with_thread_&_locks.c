/* 
   Updated the previous commit to redo the counting using threads. To see if this speeds up the progream. As we can see in the output, it did not. 
   Also, the count is incorrect. 
   In the next commit we will fix this issue via multex etc. This code should be read from the first commit to later commits in sequence to understand 
   how we are improving the issues we see in the code. 
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>  
#include <stdint.h> // uint32_t
#include <time.h>   // timer_t 

#define BIG_COUNT 1000000000UL
uint32_t count = 0; 

void *count_to_big (void *var) {
    for(uint32_t i = 0; i < BIG_COUNT; i++){
        count++;
    }
}

int main(){

    time_t start_time, end_time;
    pthread_t tid1; 
    pthread_t tid2;
    
    start_time = time( NULL );
    pthread_create(&tid1, NULL, count_to_big, NULL);
    pthread_create(&tid2, NULL, count_to_big, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    end_time = time( NULL );
    
    printf("Done, Count = %u\n", count);
    
    printf( "Elapsed time: %f seconds\n",
        difftime( end_time, start_time ) );

    return 0;
}
