# Funções Práticas de Programação Concorrente (C/POSIX)

Este documento reúne as funções mais importantes para criação, controle de processos, e manipulação de arquivos e sinais.

---

## I. Funções de Processo (Criação, ID e Sincronização)

### `fork()`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| Cria um novo processo (processo **filho**), que é uma cópia quase exata do pai. | Não recebe parâmetros. | **0** → para o processo filho.<br>**> 0** → PID do filho para o processo pai.<br>**-1** → em caso de erro. |

### `execvp(const char *file, char *const argv[])`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| **Substitui** o processo atual por um **novo programa** (não retorna ao código anterior). | `file` → nome do programa a executar (ex: `"cp"`).<br>`argv[]` → vetor de strings dos argumentos, terminando com `NULL`. | **Não retorna em caso de sucesso** (o processo é substituído).<br>**-1** → em caso de erro. |

### `getpid()`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| Obtém o **PID (Process ID)** do processo em execução. | Não recebe parâmetros. | Inteiro positivo com o PID do processo atual. |

### `getppid()`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| Obtém o **PID do processo pai** (PPID). | Não recebe parâmetros. | Inteiro positivo com o PID do processo pai. |

### `wait(int *status)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| O processo pai **aguarda** o término de **qualquer filho**. | `status` → ponteiro para armazenar o status de término (pode ser `NULL`). | PID do filho terminado.<br>**-1** em caso de erro. |

### `waitpid(pid_t pid, int *status, int options)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| O processo pai **aguarda** o término de um filho **específico**. | `pid` → PID do filho a aguardar.<br>`status` → ponteiro para o status de término (pode ser `NULL`).<br>`options` → opções de espera (ex: `0` para padrão). | PID do filho terminado.<br>**-1** em caso de erro. |

### `exit(int status)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| Encerra imediatamente o processo atual **voluntariamente**. | `status` → código de saída (normalmente `0` para sucesso). | Não retorna (o processo termina). |

### `prctl(PR_SET_NAME, ...)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| Altera o **nome do processo** (utilitário específico do Linux). | `PR_SET_NAME` (opção para definir o nome).<br>Arg 2 (a string) → nome desejado. | **0** → em caso de sucesso.<br>**-1** → em caso de falha. |

---

## II. Funções de Arquivo e Diretório

### `fopen(const char *filename, const char *mode)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| Abre um arquivo (ex: para leitura, escrita - `"w"`). | `filename` (nome/caminho), `mode` (modo de abertura). | Ponteiro `FILE*` para o arquivo aberto / `NULL`. |

### `fclose(FILE *stream)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| Fecha um arquivo aberto. | Ponteiro `FILE*` para o arquivo. | **0** → em caso de sucesso.<br>**EOF** em caso de erro. |

### `unlink(const char *pathname)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| **Deleta um arquivo** (remove o link). | `pathname` (caminho do arquivo). | **0** → em caso de sucesso.<br>**-1** e seta `errno`. |

### `mkdir(const char *pathname, mode_t mode)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| **Cria um novo diretório**. | `pathname` (caminho), `mode` (permissões iniciais, ex: `0777`). | **0** → em caso de sucesso.<br>**-1** e seta `errno`. |

### `rmdir(const char *pathname)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| **Deleta um diretório** (só funciona se o diretório estiver **vazio**). | `pathname` (caminho do diretório). | **0** → em caso de sucesso.<br>**-1** e seta `errno`. |

### `chmod(const char *pathname, mode_t mode)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| **Altera as permissões** (modo de proteção) de um arquivo. | `pathname` (caminho), `mode` (oito hexadecimal para permissões). | **0** → em caso de sucesso.<br>**-1** e seta `errno`. |

---

## III. Funções de Sinal (Comunicação entre Processos)

### `kill(pid_t pid, int sig)`

| O que faz | Entrada | Retorno / Saída |
| :--- | :--- | :--- |
| Envia um **sinal** para um processo ou grupo de processos. | `pid` (o PID do processo a receber o sinal).<br>`sig` (a constante do sinal, ex: `SIGALRM` ou `SIGCONT`). | **0** → em caso de sucesso.<br>**-1** e seta `errno`. |

### Sinais Comuns (Constantes)

| SINAL | O que faz |
| :--- | :--- |
| **`SIGALRM`** | Sinal de **alarme**, usado para notificar que o tempo esgotou (ou para interromper uma operação). |
| **`SIGCONT`** | Sinal de **continuação**, usado para retomar um processo que está parado (suspende a parada). |