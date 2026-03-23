#include <stdio.h>

int main (void)
{

    FILE *file;
    file = fopen("8D9BF61F3812", "w");

    if (file) {
        printf("Arquivo criado com sucesso.\n");
        fclose(file);
    } else {
        perror("Erro ao criar arquivo");
    }

    return 0;
}