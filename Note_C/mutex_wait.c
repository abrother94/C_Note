#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void* child(void *ptr) 
{
    int x; 
    x = *((int *) ptr);
    printf("Thread %d: Waiting to enter critical region...\n", x);
    pthread_mutex_lock( &mutex1 ); 
    printf("Thread %d: Now in critical region...\n", x);
    sleep(1);
    printf("Thread %d: Exiting critical region...\n", x);
    pthread_mutex_unlock( &mutex1 ); 
    pthread_exit(NULL);
}


int main() 
{
    int i[2];
    i[0] = 0; /* argument to threads */
    i[1] = 1;

    pthread_t t1, t2;
    pthread_create(&t1, NULL, child, (void *) &i[0]);
    pthread_create(&t2, NULL, child, (void *) &i[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
