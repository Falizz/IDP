#include <stdio.h>

int calcular_fatorial_recursivo (int n){
    if (n == 0) return 1;
    return n * calcular_fatorial (n-1);
}

int main (void) {

    int n;
    scanf("%d", &n);

    
}