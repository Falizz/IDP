#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key = 0x000009cc;

    int msgid = msgget(key, 0666);

    struct msgbuf msg;
    msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0);

    printf("Resposta lida da fila: %s\n", msg.mtext);

    return 0;
}