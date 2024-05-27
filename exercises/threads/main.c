#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 20

// Function executed by each thread
void* threadFunction(void* threadID) {
    long tid = (long)threadID;
    printf("Hello from thread %ld\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunction, (void*)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Thread %ld has finished\n", t);
    }

    pthread_exit(NULL);
    return 0;
}

// #include <pthread.h>
// #include <semaphore.h>
// #include <stdio.h>

// sem_t sem;
// int number = 0;
// #define max 100

// void* increment(void* arg) {
//     int thread_id = *(int*)arg;
//     for (int i = 0; i < max; i++) {
//         sem_wait(&sem); // Wait for the semaphore to be available
//         printf("Thread %d is incrementing the number\n", thread_id);
//         number++;
//         sem_post(&sem); // Release the semaphore
//     }
//     return NULL;
// }

// int main(int argc, char* argv[]) {

//     pthread_t t1;
//     int t1_id = 1;
//     pthread_t t2;
//     int t2_id = 2;

//     sem_init(&sem, 0, 1); // Initialize the semaphore
//     pthread_create(&t1, NULL, increment, &t1_id);
//     pthread_create(&t2, NULL, increment, &t2_id);

//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);

//     printf("Final number: %d\n", number);

//     sem_destroy(&sem); // Destroy the semaphore

//     return 0;
//     return 0;
// }