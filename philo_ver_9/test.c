#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *test1(void *argu)
{
    int *a = argu;

    for (int i = 0; i < 10; i++)
    {
        (*a)++;
    }
    return 0;
}

void *test2(void *argu)
{
    int *a = argu;
    *a *= 2;
    return 0;
}

int main(void)
{
    pthread_t *threads;
    int *a;

    threads = malloc(sizeof(pthread_t) * 2);
    a = malloc(sizeof(int));

    *a = 0;
    printf("before: %d\n", *a);
    
    pthread_create(&threads[0], NULL, test1, a);
    pthread_join(threads[0], NULL);
    printf("first: %d\n", *a);
    
    sleep(10);
    
    pthread_create(&threads[1], NULL, test2, a);
    pthread_join(threads[1], NULL);
    printf("second: %d\n", *a);

    free(a);
    free(threads);
    return 0;
}
