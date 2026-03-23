#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int remove_recursivo(const char *caminho) {
    struct dirent *entrada;
    DIR *dir = opendir(caminho);
    char caminhoCompleto[512];

    if (!dir) {
        perror("Erro ao abrir diretório");
        return -1;
    }

    while ((entrada = readdir(dir)) != NULL) {
        // Ignorar "." e ".."
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0)
            continue;

        snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/%s", caminho, entrada->d_name);

        struct stat st;
        if (stat(caminhoCompleto, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                // É diretório → chama recursivamente
                remove_recursivo(caminhoCompleto);
            } else {
                // É arquivo → deleta
                unlink(caminhoCompleto);
            }
        }
    }

    closedir(dir);

    // Agora diretório está vazio, pode remover
    return rmdir(caminho);
}

int main() {
    const char *dir = "/desafio/me_deleta-8BA19821202E";

    if (remove_recursivo(dir) == 0) {
        printf("Diretório e conteúdo removidos com sucesso!\n");
    } else {
        perror("Erro ao remover diretório");
    }

    return 0;
}
