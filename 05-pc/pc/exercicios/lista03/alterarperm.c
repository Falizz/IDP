#include <stdio.h>
#include <sys/stat.h>

int main (void)
{

    const char *arquivo = "A556A2776251.txt";

    if (chmod(arquivo, 0444) == 0) {
        printf("Permissões alteradas com sucesso.\n");
    } else {
        perror("Erro ao alterar permissões");
    }

    return 0;
}