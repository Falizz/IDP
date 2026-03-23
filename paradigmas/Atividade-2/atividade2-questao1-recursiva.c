#include <stdio.h>
#include <math.h>

unsigned long long fatorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fatorial(n - 1);
}

double aproximacao_ex(int n, double x) {
    if (n == 0) {
        return 1.0;
    }
    return aproximacao_ex(n - 1, x) + (pow(x, n) / fatorial(n));
}

int main(void) {
    unsigned long long int n;
    double x;

    scanf("%llu %lf", &n, &x);

    printf("%.10f\n", aproximacao_ex(n, x));

    return 0;
}