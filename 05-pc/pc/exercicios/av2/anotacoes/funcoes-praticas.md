# Resumo de Funções de Concorrência e Threads (Pthreads & IPC)

Este documento resume as principais funções utilizadas nos exemplos de código (`museu.c`, `lockrecursivo.c`, `trylock.c`, `chamada.c`, `Wake.c`).

---

## 1. Gerenciamento Básico de Threads (`pthread.h`)

Funções essenciais para criar e controlar o ciclo de vida das threads.

### `pthread_create`
* **Sintaxe:** `pthread_create(&thread_id, NULL, funcao_alvo, arg);`
* **O que faz:** Cria uma nova thread.
* **Argumentos:** Ponteiro para a variável da thread, atributos (geralmente NULL), função que a thread executará e argumentos para essa função.
* **Onde aparece:** Em quase todos os códigos para iniciar a execução paralela.

### `pthread_join`
* **Sintaxe:** `pthread_join(thread_id, NULL);`
* **O que faz:** Bloqueia a execução da thread principal (ou chamadora) até que a thread especificada (`thread_id`) termine.
* **Utilidade:** Garante que o `main` não encerre antes das threads trabalhadoras terminarem.

### `pthread_exit`
* **Sintaxe:** `pthread_exit(NULL);`
* **O que faz:** Encerra a thread atual explicitamente.
* **Nota:** Se usado no `main`, permite que as outras threads continuem rodando mesmo que a função `main` termine.

### `pthread_self`
* **Sintaxe:** `pthread_self()`
* **O que faz:** Retorna o ID da thread atual (tipo `pthread_t`).
* **Onde aparece:** `trylock.c` (para identificar quem está bebendo água).

### `syscall(SYS_gettid)`
* **Sintaxe:** `syscall(SYS_gettid)`
* **O que faz:** Retorna o ID numérico da thread no nível do sistema operacional (Kernel). Diferente de `pthread_self`, que retorna um identificador interno da biblioteca.
* **Onde aparece:** `chamada.c` (para obter um ID único numérico do aluno).

---

## 2. Mutexes - Exclusão Mútua (`pthread.h`)

Usados para proteger regiões críticas, garantindo que apenas uma thread acesse um recurso por vez.

### Ciclo Básico
1.  **`pthread_mutex_init(&mutex, NULL)`**: Inicializa o mutex.
2.  **`pthread_mutex_lock(&mutex)`**: Tenta pegar a trava. Se já estiver travado, a thread **dorme** (bloqueia) até liberar.
3.  **`pthread_mutex_unlock(&mutex)`**: Libera a trava, acordando threads que estejam esperando.
4.  **`pthread_mutex_destroy(&mutex)`**: Destrói o mutex e libera recursos.

### Funções Especiais de Mutex

#### `pthread_mutex_trylock`
* **Sintaxe:** `pthread_mutex_trylock(&mutex)`
* **O que faz:** Tenta pegar a trava.
    * Se conseguir: Retorna `0` e trava o mutex.
    * Se falhar (já estiver travado): Retorna um código de erro (ex: `EBUSY`) imediatamente, **sem bloquear** a thread.
* **Onde aparece:** `trylock.c` (se o bebedouro está ocupado, a thread reclama e espera um pouco, em vez de dormir na fila do mutex).

#### Mutex Recursivo (`pthread_mutexattr_*`)
Permite que a **mesma thread** trave o mesmo mutex várias vezes sem entrar em *deadlock* (travamento eterno).
* **`pthread_mutexattr_init`**: Prepara uma variável de configuração.
* **`pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE)`**: Define o tipo como recursivo.
* **`pthread_mutex_init(&mutex, &attr)`**: Inicializa o mutex com essa configuração.
* **Onde aparece:** `lockrecursivo.c` (função `foo` chama `bar`, e ambas dão lock no mesmo mutex).

---

## 3. Semáforos (`semaphore.h`)

Usados para controle de acesso (sinalização) e controle de capacidade (recursos finitos).

### `sem_init`
* **Sintaxe:** `sem_init(&semaforo, 0, valor_inicial);`
* **O que faz:** Inicializa o semáforo.
    * `0`: Indica que é compartilhado entre threads (não processos).
    * `valor_inicial`: Quantidade de recursos disponíveis (ex: capacidade da sala).

### `sem_wait` (Operação Down/P)
* **Sintaxe:** `sem_wait(&semaforo);`
* **O que faz:** Decrementa o valor do semáforo.
    * Se valor > 0: Decrementa e continua.
    * Se valor == 0: A thread **bloqueia** e espera.

### `sem_post` (Operação Up/V)
* **Sintaxe:** `sem_post(&semaforo);`
* **O que faz:** Incrementa o valor do semáforo. Se houver threads esperando, uma delas é acordada.

### `sem_destroy`
* **Sintaxe:** `sem_destroy(&semaforo);`
* **O que faz:** Libera os recursos do semáforo.

* **Onde aparecem:** `museu.c` (controlando a capacidade das salas e o acesso ao guia).

---

## 4. Baixo Nível e IPC (Inter-Process Communication)

Funções avançadas para comunicação entre processos e sincronização via Kernel (Linux).

### Futex (`linux/futex.h`)
* **`syscall(SYS_futex, addr, FUTEX_WAKE, val, ...)`**:
    * **O que faz:** Chama diretamente o Kernel para acordar threads/processos que estejam dormindo em um endereço de memória específico.
    * **FUTEX_WAKE**: Operação para acordar processos.
    * **Onde aparece:** `Wake.c` (usado para acordar manualmente um processo travado).

### Memória Compartilhada (`sys/shm.h`)
* **`shmget`**: Cria ou acessa um segmento de memória compartilhada (baseado em uma chave).
* **`shmat`**: "Attach". Anexa a memória compartilhada ao espaço de endereço do processo atual (retorna um ponteiro usável).
* **`shmdt`**: "Detach". Desanexa a memória.
* **Onde aparece:** `Wake.c` (necessário para que o `futex` funcione entre processos diferentes, pois eles precisam olhar para o mesmo endereço físico de memória).