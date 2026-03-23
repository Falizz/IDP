#include <stdio.h>

int calcular_fatorial_bottom_up (int n){
    if (n == 0) {
        return 1;
    }
    for (int i = n; i > 0; i--){
        n *= n-1;
        
    }
    return n;
}
