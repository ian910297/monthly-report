#define _GNU_SOURCE

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 2
#define MAX_LOOP 1000000

typedef struct _CONFIG {
    int a;
    int padding[15];
    int b;
} CONFIG;

CONFIG config;
void* task1(void *arg) {
    for (int i=0; i<MAX_LOOP; i++)
        config.a += 1;
}

void* task2(void *arg) {
    for (int i=0; i<MAX_LOOP; i++)
        config.b += 1;
}

int main(int argc, char *argv[]) {
    config.a = 0;
    config.b = 0;

    pthread_attr_t attr;
    cpu_set_t cpus;
    pthread_attr_init(&attr);

    pthread_t threads[NUMBER_OF_THREADS];
    for (int i=0; i<NUMBER_OF_THREADS; i++) {
       CPU_ZERO(&cpus);
       CPU_SET(i, &cpus);
       pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpus);
       if (i==0) {
        pthread_create(&threads[i], &attr, task1, NULL);
       } else if (i==1) {
        pthread_create(&threads[i], &attr, task2, NULL);
       }
    }

    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
