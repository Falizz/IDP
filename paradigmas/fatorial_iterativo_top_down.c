#include <stdio.h>

int calcular_fatorial_top_down (int n){
    if (n == 0){
        return 1;
    }
    for (int i = 1; i >= n; i++){
        n *= n-i;
    }
    return n;
}