#include <stdio.h>
#include <pthread.h>

void* printHello(void* id) {
    printf("Hello from Thread %ld\n", (long)id);
    return NULL;
}

int main() {
    pthread_t threads[2];

    for (long i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, printHello, (void*)i);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
