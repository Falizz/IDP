#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main() {

    key_t key = 0x20309be8;
    int shmid = shmget(key, 0, 0);
    char *mensagem = (char *) shmat(shmid, NULL, 0);

    printf("Mensagem lida da memória: %s\n", mensagem);

    return 0;
}