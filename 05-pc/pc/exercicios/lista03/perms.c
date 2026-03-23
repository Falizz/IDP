#include <stdio.h>
#include <sys/stat.h>

int main (void)
{

    FILE *file;
    file = fopen("673CB1DDD6F0", "w");

    if (file) {
        printf("Arquivo criado com sucesso\n");
        fclose(file);

        if (chmod("673CB1DDD6F0", 0246) == 0) {
            printf("Permissões alteradas com sucesso.\n");
        } else {
            perror("Erro ao alterar permissões");
        }

    } else {
        printf("Erro ao criar o arquivo\n");
    }

    return 0;
}