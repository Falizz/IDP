#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/syscall.h>
#include <linux/futex.h>
#include <errno.h>

static long sys_futex(void *addr1, int op, int val1, 
                      struct timespec *timeout, void *addr2, int val3) {
    return syscall(SYS_futex, addr1, op, val1, timeout, addr2, val3);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <chave_shm_em_hex>\n", argv[0]);
        printf("Exemplo: %s 0x1234abcd\n", argv[0]);
        return 1;
    }

    key_t key = (key_t)strtol(argv[1], NULL, 0); 

    printf("Tentando acessar memória com a chave: 0x%x\n", key);

    int shmid = shmget(key, 0, 0666);
    if (shmid < 0) {
        perror("Erro no shmget (verifique se a chave está correta e o programa alvo está rodando)");
        return 1;
    }

    int *futex_addr = (int *)shmat(shmid, NULL, 0);
    if (futex_addr == (void *)-1) {
        perror("Erro no shmat");
        return 1;
    }

    printf("Memória anexada com sucesso. Endereço virtual local: %p\n", futex_addr);
    printf("Enviando sinal FUTEX_WAKE...\n");

    int ret = sys_futex(futex_addr, FUTEX_WAKE, 1, NULL, NULL, 0);

    if (ret < 0) {
        perror("Erro na syscall futex");
    } else {
        printf("Sucesso! %d processo(s) acordado(s).\n", ret);
    }

    shmdt(futex_addr);

    return 0;
}