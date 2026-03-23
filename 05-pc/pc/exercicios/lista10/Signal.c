#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <signal.h>     
#include <sys/types.h>  

volatile sig_atomic_t g_sinal_recebido = 0;

void signal_handler(int signo) {
    g_sinal_recebido = signo;
}

int main(int argc, char *argv[]) {

    // Converte o argumento (texto) para um número (PID)
    pid_t exercicio_pid = 8;
    pid_t validador_pid = 0;
    
    printf("Monitorando sinais...\n");

    // (TSTP, TTIN, TTOU, URG, XCPU, XFSZ, VTALRM, PROF, WINCH, POLL, PWR, SYS)
    signal(SIGTSTP,  signal_handler);
    signal(SIGTTIN,  signal_handler);
    signal(SIGTTOU,  signal_handler);
    signal(SIGURG,   signal_handler);
    signal(SIGXCPU,  signal_handler);
    signal(SIGXFSZ,  signal_handler);
    signal(SIGVTALRM, signal_handler);
    signal(SIGPROF,  signal_handler);
    signal(SIGWINCH, signal_handler);
    signal(SIGPOLL,  signal_handler);
    signal(SIGPWR,   signal_handler);
    signal(SIGSYS,   signal_handler);

    // 1. Envia o sinal SIGSYS para "acordar" o processo 'exercicio'
    printf("Enviando SIGSYS para 'exercicio' (PID %d)\n", exercicio_pid);
    if (kill(exercicio_pid, SIGSYS) == -1) {
        perror("Erro ao enviar SIGSYS");
        return 1;
    }

    // 2. Pausa o nosso programa e espera o sinal de volta
    printf("Aguardando sinal de resposta do 'exercicio'...\n");
    pause();

    // 3. O handler foi executado e 'g_sinal_recebido' tem o valor!
    if (g_sinal_recebido == 0) {
        printf("Algo deu errado. Nenhum sinal capturado.\n");
        return 1;
    }
    printf("SINAL CAPTURADO! Número do sinal: %d\n", g_sinal_recebido);

    return 0;
}