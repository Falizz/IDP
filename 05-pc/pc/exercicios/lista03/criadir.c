#include <stdio.h>
#include <sys/stat.h>

int main (void)
{

    const char *pasta = "/home/idp/D3ACFDE03200";

    if (mkdir(pasta, 0777) == 0) {
        printf("Pasta criada com sucesso.\n");
    } else {
        perror("Erro ao criar pasta");
    }

    return 0;
}