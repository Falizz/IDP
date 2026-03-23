# Lista de Revisão - Escalonamento e Comunicação entre Processos

---

## Questão 1 - Algoritmos de Escalonamento

**Relacione os algoritmos de escalonamento com a característica que melhor o descreve:**

| Característica | Algoritmo |
|---|---|
| Processos são executados pela ordem de requisição à CPU | |
| Uso da CPU é dado pelo sorteio de bilhetes que os processos possuem | |
| Cada processo tem seu tempo de uso à CPU limitado por um tempo o qual faz com que estes percam acesso à CPU e retornem para uma fila circular de processos prontos | |
| Processos são executados de acordo com o tempo de execução, iniciando-se daquele com menor tempo de execução, porém se um processo novo requisita uso de CPU e seu tempo é menor do que aquele em execução, o que solicitou ganha acesso à CPU | |
| Cada processo possui uma precedência e processos com maior precedência executam primeiro | |
| Processos são executados de acordo com o tempo de execução, iniciando-se daquele com menor tempo de execução | |

**Opções:** SJF, Round-Robin, Prioridades, SRTN, Loteria, FIFO

---

## Questão 2 - Cálculo de Turnaround

**Cinco processos entram na fila de pronto do escalonador no mesmo instante e na seguinte ordem: P1, P2, P3, P4 e P5. Os tempos de execução de cada um dos processos P1 a P5 são 12, 10, 7, 7 e 24. Calcule o turnaround médio do sistema para os seguintes algoritmos:**

### FIFO
Resposta: _______________

### SJF
Resposta: _______________

### Round-Robin (quantum: 10)
Resposta: _______________

---

## Questão 3 - Escalonamento de Processos (V/F)

**No que diz respeito ao Escalonamento de Processos, assinale as assertivas verdadeiras:**

- [ ] a. Escalonamento de processos é algo que permite melhorar a disponibilidade das cargas de trabalho programando a capacidade antes da carga prevista
- [ ] b. Um critério fundamental em algoritmos de escalonamento é que eles devem garantir que a política de escalonamento esteja funcionando
- [ ] c. O escalonador é a parte do SO encarregada de decidir, entre os processos prontos, qual será o próximo processo a ser executado
- [ ] d. O escalonador é a parte do SO encarregada de decidir, entre os processos bloqueados, qual será o próximo processo a ser executado
- [ ] e. Um critério fundamental em algoritmos de escalonamento é que eles devem ser justos
- [ ] f. Quantum é um tempo de compartilhamento de mesmo tamanho, no algoritmo de escalonamento round-robin, utilizado para distribuir parcelas de processamento de forma equitativa entre processos
- [ ] g. Um critério fundamental em algoritmos de escalonamento é que eles devem garantir que as partes do Sistemas Operacional estejam sempre disponíveis
- [ ] h. Um critério fundamental em algoritmos de escalonamento é que eles devem garantir a inicialização do sistema
- [ ] i. Os componentes de um escalonador são o escalonador (escolhe a próxima tarefa) e o descontratante (quebra contratos de execução, finalizando processos)
- [ ] j. Escalonamento de processos é o ato de realizar o chaveamento dos processos ativos, de acordo com regras bem estabelecidas, de forma que todos os processos tenham chance de utilizar CPU
- [ ] k. Um critério fundamental em algoritmos de escalonamento é que eles devem garantir que as partes do Sistemas Operacional estejam sempre ocupadas

---

## Questão 4 - Threads (V/F)

**Sobre a abstração Threads, assinale as assertivas verdadeiras:**

- [ ] a. Threads podem ler e escrever na pilha ou nas variáveis globais de outra thread
- [ ] b. Thread é uma abstração que permite a um programa ter mais de um espaço de endereços ao mesmo tempo
- [ ] c. Em um mesmo processo, cada thread tem sua própria pilha de execução
- [ ] d. Threads compartilham um mesmo espaço de endereços
- [ ] e. No modelo de threads do modo kernel, o sistema operacional não precisa ter conhecimento a respeito das suas criações ou sistema de escalonamento das threads
- [ ] f. Threads de diferentes processos compartilham o mesmo espaço de endereços
- [ ] g. Criação de threads são mais rápidas do que a criação de processos
- [ ] h. No modelo de threads do modo usuário, o sistema operacional não tem conhecimento a respeito das suas criações ou sistema de escalonamento
- [ ] i. Thread é uma abstração que permite a um programa ter mais de um fluxo de execução ao mesmo tempo

---

## Questão 5 - Modelos de Comunicação entre Processos

**Relacione quais são os dois modelos fundamentais de comunicação entre processos:**

| Conceito | Modelo |
|---|---|
| É estabelecida uma área de memória onde processos podem ler ou escrever nela | |
| Toda a comunicação é feita por meio de troca de mensagens | |

**Opções:** Memória Exclusiva, Memória Compartilhada, Memória Distribuída

---

## Questão 6 - Mecanismos de Comunicação entre Processos

**São mecanismos de comunicação entre processos:**

- [ ] a. Pipes Anônimos
- [ ] b. Pipes Nomeados
- [ ] c. Sinais
- [ ] d. Arquivos mapeados em memória
- [ ] e. Threads
- [ ] f. Arquivos
- [ ] g. Processos
- [ ] h. Sockets
- [ ] i. Memória Compartilhada
- [ ] j. MMU
- [ ] k. Memória Cache
- [ ] l. /dev/null
- [ ] m. Filas de Mensagens
- [ ] n. Drivers

---

## Questão 7 - Condições de Corrida (V/F)

**Acerca do tópico Condições de Corrida, assinale as assertivas verdadeiras:**

- [ ] a. Condições de Corrida são situações onde dois ou mais processos estão acessando dados compartilhados
- [ ] b. Uma das condições para se evitar condições de corrida é permitir que pelo menos um processo que esteja fora de sua região crítica possa bloquear a execução de outro processo
- [ ] c. Em uma situação de condição de corrida, o resultado da execução depende da ordem de execução pelo tempo
- [ ] d. Uma das condições para se evitar condições de corrida é garantir que dois ou mais processos não entrem ao mesmo tempo em suas regiões críticas
- [ ] e. Exclusão Mútua é o ato de impedir que dois ou mais processos acessem um mesmo recurso ao mesmo tempo
- [ ] f. Uma das condições para se evitar condições de corrida é mensurar a velocidade relativa de todos os processos
- [ ] g. Região Crítica é a parte do código que leva a uma condição de corrida
- [ ] h. Região Crítica é a parte do código que não se deve garantir uma execução com sucesso
- [ ] i. Uma das condições para se evitar condições de corrida é garantir que nenhum processo espere indefinidamente para entrar em sua região crítica
- [ ] j. Uma das condições para se evitar condições de corrida é garantir que apenas processos "problemáticos" esperem indefinidamente para entrar em sua região crítica
- [ ] k. Uma das condições para se evitar condições de corrida é não fazer considerações a respeito da velocidade relativa de processos
- [ ] l. Uma das condições para se evitar condições de corrida é garantir que nenhum processo que esteja fora de sua região crítica pode bloquear a execução de outro processo
- [ ] m. Exclusão Mútua é o ato de impedir que dois ou mais processos utilizem a CPU ao mesmo tempo

---

## Questão 8 - Conceitos de Comunicação entre Processos

**Sobre os conceitos envolvendo Comunicação entre Processos, relacione os conceitos com os seus respectivos tópicos:**

| Conceito | Termo |
|---|---|
| Mecanismo de sincronização entre processos/threads de forma que estes sejam programados baseados na verificação de uma variável compartilhada | |
| Impedir que dois ou mais processos acessem um mesmo recurso ao mesmo tempo | |
| Operação que é ser executada completamente em caso de sucesso, ou abortada completamente em caso de erro | |
| Parte do código onde é feito o acesso à memória compartilhada | |
| Situação onde dois ou mais processos estão acessando dados compartilhados e o resultado final do processamento depende de quem executa e quando executa | |
| Técnica em que um processo verifica uma condição repetidamente até que ela seja verdadeira | |

**Opções:** Operação Atômica, Espera Ocupada, Exclusão Mútua, Condição de Corrida, Lock, Região Crítica

---

## Questão 9 - Bloqueio de Processos (V/F)

**Sobre soluções envolvendo o bloqueio de processos, assinale as assertivas verdadeiras:**

- [ ] a. Semáforo sozinho não garante exclusão mútua
- [ ] b. As duas operações em variáveis de condição são Up() e Down()
- [ ] c. A espera ocupada é uma técnica para evitar o desperdício de CPU
- [ ] d. Monitor é um mecanismo que agrupa funcionalidades com acesso a regiões críticas por meio de módulos gerenciados pelo compilador
- [ ] e. Um semáforo é uma variável inteira para contar sinais de acordar, utilizada para controlar o acesso a recursos compartilhados
- [ ] f. Um dos objetivos de se utilizar a estratégia de Dormir e Acordar, é para se evitar o desperdício de CPU
- [ ] g. Variáveis de condições possuem memória exclusiva
- [ ] h. Variáveis de condição servem para permitir que um processo bloqueie a si próprio na espera de uma ação por outro processo
- [ ] i. Mutex é uma variável compartilhada de dois estados, utilizada para conceder acesso a recursos compartilhados, porém somente um por vez

---

## Questão 10 - Deadlocks (Impasses)

**Associe os conceitos com os seus respectivos termos, sobre o tópico de Deadlocks (Impasses):**

| Conceito | Termo |
|---|---|
| Caso onde a política de alocação não causa um deadlock, porém há processos que nunca conseguem utilizar um recurso desejado | |
| Recursos cujo a liberação somente ocorre por espontânea vontade do processo que o detém | |
| Recursos que podem ser retirados do processo por uma entidade externa | |
| Processo que não encontra-se bloqueado, mas está impossibilidade de prosseguir sua execução de alguma forma | |
| São objetos que um processo pode adquirir de maneira exclusiva ou não | |

**Opções:** Starvation (inanição), Recurso Preemptivo, Recurso Não-Preemptivo, Livelock, Recursos

---

## Questão 11 - Análise de Threads com Mutex

**Dadas duas threads P1 e P2, que possuem o seguinte código:**

```c
// P1
void * P1() {
    pthread_mutex_lock(&mutex);
    a = 2 * d;
    pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&mutex);
    g = 1 - a;
    pthread_mutex_unlock(&mutex);
}
```

```c
// P2
void * P2() {
    pthread_mutex_lock(&mutex);
    d = 1 * a; 
    pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&mutex);
    g = 1 * g;
    pthread_mutex_unlock(&mutex);
}
```

**Sabendo-se que ambas as threads compartilham um único lock chamado mutex, e que as variáveis a, d e g são variáveis globais, considerando que os valores iniciais de a = -1, d = -5 e g = -5, quais são todas as possíveis saídas para os valores de a, d, e g?**

- [ ] a. (-10, -10, 11), (-2, -1, 3), (-10, -1, 3), (-1, -5, -5)
- [ ] b. (-1, -5, -5)
- [ ] c. (-10, -10, 11), (-1, -5, -5)
- [ ] d. (-10, -10, 11), (-2, -1, 3), (-10, -1, 3)
- [ ] e. (-10, -10, 11), (-2, -1, 3)
- [ ] f. (-2, -1, 3)
- [ ] g. (-2, -1, 3), (-10, -1, 3)
- [ ] h. (-10, -1, 3)
- [ ] i. (-2, -1, 3), (-1, -5, -5)
- [ ] j. (-10, -10, 11)
- [ ] k. (-10, -10, 11), (-10, -1, 3)
- [ ] l. (-10, -10, 11), (-2, -1, 3), (-1, -5, -5)

---

## Questão 12 - Análise de Threads com Mutex

**Dadas duas threads P1 e P2, que possuem o seguinte código:**

```c
// P1
void * P1() {
    pthread_mutex_lock(&mutex);
    d = 0 - d;
    pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&mutex);
    c = 2 + c;
    pthread_mutex_unlock(&mutex);
}
```

```c
// P2
void * P2() {
    pthread_mutex_lock(&mutex);
    c = 1 * b; 
    pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&mutex);
    c = 0 + d;
    pthread_mutex_unlock(&mutex);
}
```

**Sabendo-se que ambas as threads compartilham um único lock chamado mutex, e que as variáveis c, b e d são variáveis globais, considerando que os valores iniciais de c = 5, b = -5 e d = -4, quais são todas as possíveis saídas para os valores de c, b, e d?**

- [ ] a. (6, -5, 4), (-2, -5, 4), (4, -5, 4)
- [ ] b. (6, -5, 4)
- [ ] c. (6, -5, 4), (-2, -5, 4)
- [ ] d. (-2, -5, 4)
- [ ] e. (4, -5, 4), (-5, -5, 4)
- [ ] f. (-5, -5, 4)
- [ ] g. (6, -5, 4), (-2, -5, 4), (4, -5, 4), (-5, -5, 4)
- [ ] h. (6, -5, 4), (4, -5, 4)
- [ ] i. (-2, -5, 4), (4, -5, 4), (-5, -5, 4)
- [ ] j. (-2, -5, 4), (-5, -5, 4)
- [ ] k. (-2, -5, 4), (4, -5, 4)
- [ ] l. (4, -5, 4)

---

## Questão 13 - Estratégias para Tratar Deadlocks

**São estratégias para tratar deadlocks:**

- [ ] a. Evitar o deadlock
- [ ] b. Prevenir o deadlock
- [ ] c. Detectar e recuperar o deadlock
- [ ] d. Ignorar o problema

---

## Questão 14 - Deadlocks (V/F)

**A respeito de Deadlocks, assinale as assertivas verdadeiras:**

- [ ] a. Uma das condições para que ocorra um deadlock é a possibilidade de espera circular
- [ ] b. Tratar deadlocks é uma operação simples
- [ ] c. Livelock ocorre quando a política de alocação não causa deadlock, porém é possível que processos nunca sejam atendidos
- [ ] d. Para prevenir deadlocks, basta todos os recursos serem preemptivos
- [ ] e. Uma das condições para que ocorra um deadlock é que os recursos sejam preemptivos
- [ ] f. Um algoritmo para realizar a detecção de deadlocks é a busca em profundidade
- [ ] g. A sequência de operações ao manipular uma recurso é: requisitar e liberar
- [ ] h. Uma forma de se recuperar de deadlocks é eliminar todos os processos do sistema

---