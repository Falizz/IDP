#include <stdio.h>

int main (void){

    float media_turma = 0;
    for (int i = 0; i < 4; i++){
        char a;
        float n1, n2;

        scanf ("%c %f %f", &a, &n1, &n2);
        fgetc(stdin);

        float media = (n1 + n2) / 2;
        printf("Nome: %c\n", a);
        printf("Media: %.2f\n\n", media);

        media_turma += media;
    }
    printf("Media da turma: %.2f\n",media_turma/4);
}