/* 
   These set of examples starts with counting to a billion by two function calls. On my machine this takes about 4 seconds.
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>  
#include <stdint.h> // uint32_t
#include <time.h>   // timer_t 

#define BIG_COUNT 1000000000UL
uint32_t count = 0; 

void count_to_big () {
    for(uint32_t i = 0; i < BIG_COUNT; i++){
        count++;
    }
}

int main(){

    time_t start_time, end_time;

    start_time = time( NULL );
    count_to_big();
    count_to_big();
    end_time = time( NULL );
    
    printf("Done, Count = %u\n", count);
    
    printf( "Elapsed time: %f seconds\n",
        difftime( end_time, start_time ) );

    return 0;
}
