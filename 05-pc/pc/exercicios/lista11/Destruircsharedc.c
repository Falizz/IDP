#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main() {

    key_t key = 0x202e9b8c;
    int shmid = shmget(key, 0, 0);
    shmctl(shmid, IPC_RMID, NULL);

    printf("Sucesso! Segmento foi removido\n");

    return 0;
}