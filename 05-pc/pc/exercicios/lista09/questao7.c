#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

void *calc_25x2(void *arg) {
    double x = *(double *)arg;

    double resultado_parcial = 25.0 * x * x;

    double *retorno = (double *)malloc(sizeof(double));
    *retorno = resultado_parcial;

    pthread_exit((void *)retorno);
}


void *calc_11x3(void *arg) {
    double x = *(double *)arg;

    double resultado_parcial = 11.0 * x * x * x;

    double *retorno = (double *)malloc(sizeof(double));
    *retorno = resultado_parcial;

    pthread_exit((void *)retorno);
}

int main() {
    pthread_t threads[NUM_THREADS];
    double x;
    int status;

    void *ret_val1;
    void *ret_val2;

    printf("Digite o valor de x (double): ");

    status = pthread_create(&threads[0], NULL, calc_25x2, &x);
    status = pthread_create(&threads[1], NULL, calc_11x3, &x);
    pthread_join(threads[0], &ret_val1);
    pthread_join(threads[1], &ret_val2);

    double resultado1 = *(double *)ret_val1;
    double resultado2 = *(double *)ret_val2;
    double resultado_final = resultado1 + resultado2;

    printf("\nCálculos parciais:\n");
    printf("  25x^2 = %.4f\n", resultado1);
    printf("  11x^3 = %.4f\n", resultado2);

    printf("\nResultado final (25x^2 + 11x^3): %.4f\n", resultado_final);

    free(ret_val1);
    free(ret_val2);

    return 0;
}