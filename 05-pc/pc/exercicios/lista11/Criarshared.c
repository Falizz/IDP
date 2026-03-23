#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main() {

    key_t key = 0x20319B21;
    size_t size = 0x100;
    int shm_flg = 0644 | IPC_CREAT;
    int shmid = shmget(key, size, shm_flg);

    printf("Segmento criado com sucesso!\n");

    return 0;
}