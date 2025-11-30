//5 readers and 5 writers
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

sem_t mutex, wrt;
int sharedvar = 99;
pthread_t writers[5], readers[5];
int readercount = 0;

void *writer(void *arg) {
    int id = *((int *)arg);
    printf("\nWriter %d is trying to enter", id);

    sem_wait(&wrt);
    printf("\nWriter %d has entered CS", id);

    sharedvar++;
    printf("\nWriter %d CHANGED THE VALUE OF SHARED VAR TO %d", id, sharedvar);

    sem_post(&wrt);
    printf("\nWriter %d is out of CS", id);

    return NULL;
}

void *reader(void *arg) {
    int id = *((int *)arg);
    printf("\nReader %d is trying to enter", id);

    sem_wait(&mutex);
    readercount++;
    if (readercount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);

    printf("\nReader %d has entered CS", id);
    printf("\nReader %d READ THE VALUE OF SHARED VAR AS %d", id, sharedvar);
    sleep(1);

    sem_wait(&mutex);
    readercount--;
    if (readercount == 0)
        sem_post(&wrt);
    sem_post(&mutex);

    printf("\nReader %d is out of CS", id);
    return NULL;
}

int main() {
    int i;
    int id[5];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (i = 0; i < 5; i++) {
        id[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &id[i]);
        pthread_create(&readers[i], NULL, reader, &id[i]);
    }

    for (i = 0; i < 5; i++) {
        pthread_join(writers[i], NULL);
        pthread_join(readers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}