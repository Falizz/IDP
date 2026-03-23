# Aula 7 - Escalonamento de Processos

## 1 - Conceito Básico e Componentes

Em sistemas multiprogramados, vários processos competem pela CPU. O **Escalonador** (Scheduler) é quem decide qual processo vai rodar em seguida.

- **Despachante (Dispatcher):** É a parte "operacional". Ele realiza a troca de contexto (salva o estado do processo atual e carrega o próximo). É uma tarefa custosa (overhead).

- **Escalonador (Scheduler):** É a parte "inteligente". Ele toma a decisão lógica de quem será o próximo

## 2 - Categorias de Escalonamento

Existem duas formas principais de o sistema operacional gerenciar o tempo de CPU:

- **Preemptivo:** O SO pode interromper forçadamente um processo que está rodando para dar a vez a outro (ex: acabou o tempo dele).

- **Não Preemptivo:** O processo continua rodando até terminar, bloquear por E/S ou liberar a CPU voluntariamente. O SO não o "expulsa";

## 3 - Algoritmos de Escalonamento

1. **FIFO (Fist-In, First-out):** 
    - **Funcionamento:** Quem chega primeiro executa primeiro.
    - **Características:**
        - Não preemptivo
        - Simples, mas ineficiente se um processo longo chega na frente (efeito comboio)

2. **SJF (Shortest Job First):**
    - **Funcionamento:** O processo com **menor tempo de execução** estimadop roda primeiro
    - **Características:**
        - Não preemptivo
        - Ótimo para reduzir o tempo médio de espera, mas pode causar *inanição* (starvation) em processos longos se sempre chegarem processos curtos.
    
3. **SRTN (Shortest Remaining Time Next):**
    - **Funcionamento:** Versão **preemptiva** do SFJ. Se chegar um processo novo que demora menos do que o tempo *restante* do processo atual, ocorre a troca.

4. **Round-Robin (Circular):**
    - **Funcionamento:** Cada processo ganha uma fatia de tempo fixa chamada **Quantum**. Se não terminar nesse tempo, volta pro fim da fila.

    - **Ponto Crítico:** O tamanho do **Quantum**
        - Sefor muito pequeno, perde-se muito tempo trocando o contexto (overhead)
        - Se for muito grande, vira um FIFO

5. **Prioridades:**
    - **Funcionamento:** Processos mais importantes rodam antes.
    - **Problema:** Inanição dos processos de baixa prioridade.
    - **Solução:** *Aging* (aumentar a prioridade conforme o tempo passa) ou Múltiplas Filas.

6. **Loteria:**
    - **Funcionamento:** Processos recebem bilhetes. O escalonador sorteia um bilhete aleatoriamente para decidir quem roda.

## 4 - Sistemas de Tempo Real

- **Hard Real Time:** Pazos (deadlines) são rígidos. Atrasos são fatais
    - ex: piloto automático
- **Soft Real Time:** Atrasos ocasionais são toleráveis

---

# Aula 8 - Threads

## 1 - O Conceito: Processo vs. Thread

Antes, um processo era uma "caixa" com uma única linha ed execução. Agora, separamos as coisas:

- **Processo:** É o "ambiente" ou contêiner. Ele segura os recursos compartilhados (memória, arquivos abertos, variáveis globais).

- **Thread (Linha de Execução):** É a entidade que realmente executa o código (a "alma" do processo).
    - **O que elas compartilham:** O espaço de endereçamento (memória) e arquivos abertos. Se uma thread muda uma variável global, todas as outras veem.
    - **O que é privado de cada thread:** Cada uma tem  seu próprio contador de programa (onde está no código), registradores e **sua própria pilha** (stack).

## 2 - Porque usar Threads? (Vantagens)

- **Desempenho:** Permite sobrepor atividades. Enquanto uma thread espera um dado do disco (I/O), ou tra usa a CPU para calcular.

- **Velocidade de Criação:** Criar e destruir uma thread é muito mais rápido (até 100x) do que criar um processo novo, pois não precisa duplcar a memória inteira.

- **Paralelismo Real:** Em computadores com várias CPUs (multicore), threads diferentes podem rodar em núcleos diferentes simultaneamente.

## 3 - Níveis de Implementação

Onde a thread "vive"? Existem três formas de implementar:

1. **Modo Usuário (User Space):**
    - **Como funciona:** O SO (Kernel) não sabe que as threads existem. Ele acha que é um processo normal de uma thread só. Uma biblioteca gerencia a troca de threads internamente.
    - **Prós:** Troca de contexto rapidíssima (não chama o Kernel).
    - **Contras:** Se uma thread travar esperando I/O (bloqueante), o **processo inteiro trava**, porque o Kernel bloqueia o processo todo.

2. **Modo Núcleo (Kernel Space):**
    - **Como funciona:** O Windows e Linux mordernos usam isso. O Kernel sabe que as threads existem e as gerencia em sua tabela.
    - **Prós:** Se uma thread bloquear, as outras continuam rodando. Aproveita múltiplos processadores.
    - **Contras:** Gerenciamento mais "caro" (lento) porque envolve chamadas de sistema.

3. **Híbrido:**
    - **Como funciona:** Tenta pegar o melhro dos dois mundos. Mapeia *N* threads de usuário em *M* threads de núcleo.

## 4 - Modelos de Organização (Arquitetura Interna)

Como as threads colaboram para resolver um problema?

- **Dispatcher/Worker (Despachante/Operário):** Uma thread "chefe" recebe as requisições e distribui para as threads "operárias" processarem. Muito comum em servidores Web.

- **Team (Time):** Todas olham para uma "caixa de entrada" comum, pegam o primeiro trabalho disponível e execytam.

- **Pipeline:** Linha de montagem. A saída de uma thread vira a entrada da próxima. A primeira lê, a segunda processa, a terceira salva.

## 5 - O Grande Problema

Como as threads compartilham a mesma memória (variáveis globais), uma pode sobrescrever o trabalho da outra se não houver cuidado. Isso cria a necessidade de **Sincronização**

---

# Aula 9 - Comunicação Entre Processos (IPC)

## 1 - O Problema: Condição de Corrida (Race Condition)

- **Definição:** Acontece quando dois ou mais processos acessam e manipulam dados compartilhados ao mesmo tempo. O resultado final depende da ordem de "quem chegou primeiro" ou de "quem foi interrompido quando". O resultado se torna imprevisível e geralmente incorreto.

- **Exemplo Clássico (Spooler de impressão):**
    - Processo A lê que a próxima posição livre no buffer de impressão é a 7.
    - Antes de gravar, o Processo A perde a CPU (é interrompido).
    - Processo B ganha a CPU, lê a mesma posição 7, grava seu arquivo lá e atualiza o contador para 8
    - Processo A volta, "acha" que a posição 7 ainda é dele, grava seu arquivo lá **sobrescrevendo** o arquivo do B. O arquivo do B é perdido.

## 2 - A Solução: Exclusão Mútua e Região Crítica

Para evitar a bagunça acima, precisamos impedir o acesso simultâneo.

- **Região Crítica:** É o trecho do código onde o processo acessa o recurso compartilhado (ex: a linha de código que escreve na variável ```saldo```).

- **Exclusão Mútua:** É a garantia de que, se um processo está dentro da sua Região Crítica, nenhum outro pode entrar na dele.

**As 4 Regras de Ouro para uma boa solução:**

1. Dois processos nunca podem estar na região crítica ao mesmo tempo.
2. Não se pode assumir nada sobre a velocidade da CPU (tem que funcionar em qualquer máquina).
3. Nenhum processo fora da região crítica pode bloquear o outro.
4. Nenhum processo pode esperar para sempre (inanição)

## 3 - Tentativas de Solução (Como implementar a Exclusão Mútua?)

1. **Soluções que NÂO funcionam bem ou tem problemas graves:**

- **Desabilitar Interrupções:** O processo desliga as interrupções do sistema ao entrar na região crítica e religa ao sair.
    - *Por que é ruim?* Dá poder demais ao usuário (se ele travar, o PC trava todo). Além disso, não funciona em multicore (vários processadores), pois desailita só em uma CPU.

- **Variáveis de Trava (Locks):** Uma variável ```lock == 0``` (livre) ou ```lock == 1``` (ocupado).
    - *Por que falha?* A própria leitura da variável ```lock``` sofre de condição de corrida. Dois processos podem ler ```lock == 0``` ao mesmo tempo e entrar juntos.

- **Estrita Alternância (Revezamento):** Um processo só entra se for a "vez" dele (variável ```turn```).
    - *Por que é ruim?* Viola a regra 3. Se o processo A for muito mais lento que o B, o B fica bloqueado esperando A, mesmo que a região crítica esteja vazia (Desperdício de CPU).

2. **Soluções que FUNCIONAM (Espera Ocupada):**

    - **Algoritmo de Peterson (Software):** Uma solução inteligente puramente via código. Usa duas variáveis: ```ìnteresse``` (eu quero entrar) e ```vez``` (de quem é a prioridade). Ele garante a exclusão mútua e evita o travamento.

    - **Instrução TSL (Hardware - Test and Set Lock):** Os processadores modernos têm uma instrução especial de hardware (hardware puro). Ela lê o valor de uma variável e escreve um novo valor ```1``` em uma única operação indivisível (atômica). Isso impede que dois processos leiam ```0``` ao mesmo tempo.

## 4 - O Problema da Espera Ocupada (Busy Waiting)

Todas as soluções acima (Peterson, TSL) usam "Espera Ocupada". Isso significa que, enquanto o processo espera pra entrar, ele fica num loop ```while``` infinito gastando 100% da CPU apenas para checar ""já liberou?". Isso desperdiça muito processamento.

---

# Aula 10 - Dormir e Acordar

## 1 - O Problema da Prioridade Invertida

Por que a "Espera Ocupada" (da aula anterior) é perigosa além de gastar energia?

- Imagine um processo de **Alta Prioridade (H)** e um de **Baixa Prioridade (L)**.

- Se **L** entra na região crítica e **H** fica pronto pra rodar, **H** (por ter prioridade) toma a CPU e fica num loop infinito testando se a região liberou.

- Como **H** não larga a CPU, **L** nunca consegue rodar para sair da região crítica. Resultado: O sistema trava.

## 2 - O Problema do Produtor-Consumidor (Buffer Limitado)

Este é o exemplo clássico usado para explicar problemas de sincronização.

- **Cenário:** Dois processos compartilham um buffer de tamanho fixo.
    - **Produtor:** Cria dados e coloca no buffer.
    - **Consumidor:** Retira dados do buffer.

- **Regras:**
    - Se o buffer estiver **cheio**, o Produtor deve dormir.
    -Se o buffer estiver **vazio**, o Consumidor deve dormir.

- **O Problema (Condição de Corrida Fatal):** Existe uma falha conhecida como "Sinal de acordar perdido" (Lost Wakeup).
    - O Consumidor vê que o buffer está vazio. Antes de dormir, ele perde a CPU.
    - O Produtor roda, coloca um dado e manda um sinal de "Acorde!" para o Consumidor.
    - Como o Consumidor ainda não estava dormindo (estava quase), o sinal se perde.
    - Quando o Consumidor volta a rodar, ele "termina de ir dormir". O Produtor enche o buffer e também dorme. Ambos dormem para sempre.

## 3 - A Solução Definitiva: Semáforos (Dijkstra)

Para resolver o problema do "sinal perdido", Dijkstra criou o **Semáforo**. Ele é uma variável inteira que conta quantos sinais de acordar foram salvos.

Ele possui duas operações atômicas (indivisíveis):
- **Down (ou P):** Tenta diminuir o valor.
    - Se o valor for > 0: Diminui e continua (entra na região).
    - Se o valor for = 0: O processo **dorme** (bloqueia).

- **Up (ou V):** Aumenta o valor.
    - Incrementa o semáforo. Se havia alguém dormindo esperando esse recurso, esse processo é **acordado**.

**Como isso resolve o Produtor-Consumidor?** Usam-se 3 semáforos:

1. ```mutex```: Garante que só um mexa no buffer por vez (Exclusão Mútua).

2. ```cheio```: Conta quantas posições estão ocupadas (sincronização)

3. ```vazio```: Conta quantas posições estão livres.

## 4 - Mutex (Mutual Exclusion)

É uma versão simplificada do semáforo.

- **Diferença:** O semáforo conta (0, 1, 2, 3...). O Mutex é binário: apenas **Destravado** ```1``` ou **Travado** ```0```.

- **Uso:** Serve apenas para proteger a região crítica (como uma chave de banheiro).

- **Vantagem:** Se a thread tenta pegar o Mutex e não ocnsegue, ela chama ```thread_yield()``` e cede a CPU, sem espera ocupada.

## 5 - Variáveis de Condição

Usadas em conjunto com Mutexes. Permitem que uma thread espere por uma condição específica (ex: "espere até ```saldo > 100```) sem gastar CPU.

- ```wait(var)```: Libera o lock e vai dormir.
- ```signal(var)```: Acorda quem está dormindo na variável.

## 6 - Monitores (Alto Nível)

Semáforos são poderosos, mas fáceis de errar (se você esquecer um ```Up```, trava tudo).

- **Conceito:** O monitor é uma construção da linguagem (como ````synchronized``` do Java). O ocmpilador coloca os semáforos/mutexes automaticamente pra você.

- **Regra:** Apenas um processo pode estar ativo dentro de um monitor por vez.

---