#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t p1_pid, p2_pid;
    
    // 1. PROCESSO PAI CRIA P1
    p1_pid = fork(); 

    // --- LÓGICA DO FILHO P1 (PID de retorno é 0) ---
    if (p1_pid == 0) {
        pid_t current_pid = getpid();
        
        printf("Filho mais velho dormiu por 4 segundos\n");
        sleep(4);
        
        printf("Filho mais velho PID %d terminando a execucao\n", current_pid);
        exit(0);
    }

    // 2. PROCESSO PAI CRIA P2
    p2_pid = fork();

    // --- LÓGICA DO FILHO P2 (PID de retorno é 0) ---
    if (p2_pid == 0) {
        pid_t current_pid = getpid();
        
        printf("Filho mais novo dormiu por 2 segundos\n");
        sleep(2);
        
        printf("Filho mais novo PID %d terminando a execucao\n", current_pid);
        exit(0);
    }

    printf("Sou pai de dois\n");

    if (waitpid(p1_pid, NULL, 0) != -1) {
        printf("P1 ja terminou sua execucao\n");
    }

    return 0;
}