#include <stdio.h>
#include <pthread.h>

int contador = 0;

void *incrementos(void *empty)
{
    for (int i = 0; i < 100; i++) {
        contador++;
    }
}

int main()
{
    pthread_t t[43];

    for (int i = 0; i < 43; i++) {
        pthread_create(&t[i], NULL, incrementos, NULL);
    }

    for (int i = 0; i < 43; i++) {
        pthread_join(t[i], NULL);
    }

    printf("O valor do contador   : %%d\n", contador);

    return 0;
}
