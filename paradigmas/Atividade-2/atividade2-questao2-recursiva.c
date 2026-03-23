#include <stdio.h>

void processar_aluno(int i) {

    if (i > 4) {
        return;
    }

    printf("Aluno %d\n", i);

    float n1, n2, a;

    printf("Prova 1: ");
    scanf("%f", &n1);
    n1 *= 0.3;

    printf("Prova 2: ");
    scanf("%f", &n2);
    n2 *= 0.3;

    printf("Atividade: ");
    scanf("%f", &a);
    a *= 0.4;

    float media = n1 + n2 + a;

    printf("Media: %.2f", media);

    if (media >= 9) printf("\nMenção SS\nAprovado\n\n");
    else if (media >= 7) printf("\nMenção MS\nAprovado\n\n");
    else if (media >= 5) printf("\nMenção MM\nAprovado\n\n");
    else if (media >= 3) printf("\nMenção MI\nReprovado\n\n");
    else if (media >= 0.1) printf("\nMenção II\nReprovado\n\n");
    else printf("\nMenção SR\nReprovado\n\n");

    processar_aluno(i + 1);
}

int main(void) {

    processar_aluno(1);

    return 0;
}