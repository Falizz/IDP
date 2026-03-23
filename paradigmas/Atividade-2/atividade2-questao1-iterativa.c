#include <stdio.h>

int main(void) {

    unsigned long long int n;
    double x;

    scanf("%llu %lf", &n, &x);

    double soma = 1.0;
    double termo = 1.0;

    for (int i = 1; i <= n; i++) {
        termo = termo * x / i;
        soma += termo;
    }

    printf("%.10f\n", soma);

    return 0;
}