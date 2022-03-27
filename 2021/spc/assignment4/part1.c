#include "slow_functions.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /*  During slow_function2 run, need use thread
        let slow_function1 run 10 times and let
        counter reach >9 and unlock the mutex to 
        print END 2.                            */

    pthread_t t0;               // slow_func01
    pthread_t slow1[10];        // slow_func02

    if(pthread_create(&t0, NULL, slow_function2, NULL)) {               // succes ret = 0 else error num
        printf("Error create thread01!!!");
        exit(0);
    }

    for(int i=0; i<10; i++) {
        // create thread for slow1 in each times
        // true only if creat return a non 0 num
        if(pthread_create(&slow1[i], NULL, slow_function1, NULL)) {
            printf("Error create thread02!!!");
            exit(0);
        }
    }

    // for each thread, join to the mian thread
    pthread_join(t0, NULL);
    for(int i=0; i<10; i++) {
        pthread_join(slow1[i], NULL);
    }
    return 0;
}