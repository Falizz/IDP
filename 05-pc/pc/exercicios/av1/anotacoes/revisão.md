# Aula 2: Introdução aos Sistemas Operacionais - Parte 01

## 1. Componentes e Definição do SO

Um computador moderno é composto por

### Hardware
- processadores
- memória
- disco
- periféricos (mouse, teclado, monitor)

### Software
- Básico
para gerenciar a operação
- Aplicativo
para auxiliar o usuário

O objetivo de um Sistema Operacional é duplo:
### A. Máquina Estendida (Extended Machine)
Oferecer aos programas de usuário um modelo de computador **melhor, mais simples e mais limpo**, escondendo os detalhes complexos do hardware

### B. Gerenciador de Recursos (Resource Manager)
Lidar com o **gerenciamento de todos os recursos** (CPU, memória, dispositivos) para alocá-los de forma **ordenada, controlada, eficiente e justa**.
O gerenciamento é feito por multiplexação (compartilhamento).
- No tempo: Programas/Usuários aguardando o recurso
(exemplo: processos executando ao mesmo tempo - multiprogramação)
- No espaço: Programas utilizando partes de um recurso ao mesmo tempo (exemplo: memória)

### Como o SO opera
O SO opera no **Modo Núcleo**, tendo acesso total ao hardware, enquanto os programas do usuário (como o **shell** ou **GUI**) operam no **Modo Usuário**, com um subconjunto restrito de instruções. A interface do usuário **não faz parte do Sistema Operacional**.

## 2. História e Gerações de Computadores/SOs

### Dispositivos Mecânicos:
Charles Babbage (pai do computador) e a Máquina Analítica. Ada Augusta (primeira programadora) escreveu instruções para ela.

### Primeira Geração (1945-1959):
Uso de **válvulas**. ENIAC (18.000 válvulas).
**Não havia Sistema Operacional**; o programador interagia diretamente com o console (mono-usuário).

### Segunda Geração (1959-1964):
* Invenção do **Transistor**.
* Surgimento dos **Mainframes**. Foco em **Proecssamento em Lotes (Batch)**, onde jobs eram agrupados para execução sequencial para reduzir o tempo desperdiçado. Uso de **temporizador** para alocar recursos por tempo definido.

### Terceira Geração (1965-1980):
* Invenção dos **Circuitos Integrados (CI)**.
* Surgimento da **Multiprogramação** (divisão da memória para múltiplas tarefas, aproveitando recursos ociosos).
* Surgimento do **Spooling** (transferência de tarefas de cartão para disco).
* **Time-Sharing** (tempo de resposta menor, permitindo que cada usuário tivesse seu terminal "online").
* Desenvolvimento do **UNIX** (a partir do PDP-7) e o surgimento do **MINIX** (versão educacional do UNIX) e posteriormente, do **Linux** (inspirado no MINIX).

### Quarta Geração (1980-):
Desenvolvimento de **Circuitos Integrados em Larga Escala (LSI)** e do **Computador Pessoal (PC)**.
Dominância inicial do **MS-DOS** (baseado em comandos de teclado) e, en seguida, do **Windows** (influenciado pela Interface Gráfica do Usuário - GUI - da Xerox PARC e Apple Macintosh).

***

# Aula 3: Revisão de Hardware e Interrupções - Parte 02

## 1. Arquitetura do Processador (CPU)

### CPU:
É o "cerébro" do computador, responsável por buscar, decodificar, executar instruções e armazenar resultados (ciclo de busca/execução).

### Registradores:
Pequenas áreas de memória interna à CPU, muito rápidas, essenciais para o ciclo de execução.

### Modos de Operação:
* **Modo Núcleo (Kernel/Supervisor/Monitor):** Acesso total a todas as instruções, incluindo E/S e registrador de palavra de estado (PSW).
* **Modo Usuário:** Subconjunto restrito de instruções; não pode executar instruções sensiveis (Como E/S). É usado por programas de aplicação.

### PSW (Progream Status Word):**
Contém bits de controle (como o bit que indica o modo de operação) e códigos de condição. O SO manipula o PSW para alternar entre os modos.

## 2. Gerenciamento de Memória
* **MMU (Memory Management Unit):** Unidade de Gerência de Memória; responsável por **mapear endereços virtuais (do programa) para endereços físicos (da memória RAM).
* É um hardware crucial que converte os endereços, permitindo que cada processo "pense" que tem acesso exclusivo à memória.

## 3. Interrupções e I/O
### Interrupções:
Mecanismo pelo quyal o hardware (dispositivos de E/S) avisa a CPU quando termina uma tarefa (ex: disco termina de ler dados).
* A interrupção força a CPu a suspender o programa atual, salvar o estado e executar um *Interrupt Service Routine (ISR)* ou *rotina de serviço de interrupção*, que é o código do SO.

### Controladores de Dispositivos:
Componentes de hardware que gerenciam a comunicação entre barramento e dispositivo (ex: controlador de disco, de vídeo).

### Portas de E/S:
Endereços de memória ou registradores usados pelo SO para se comunicar com os controladores de dispositivos.

### DMA (Direct Memory Access):
Método eficiente onde o controlador de E/S pode transferir dados diretamente para a memória sem a intervenção constante da CPU, liberando-a para outras tarefas.

## 4. Barramento

1. O **Barramento (Bus):** É o canal de comunicação que liga CPU, Memória e dispositivos de E/S.

2. **Linhas do Barramento:**
* **Linhas de Endereço:** Indicam a origem/destino da informação (memória ou porta I/O).
* **Linhas de Dados:** Transportam a informação.
* **Linhas de Controle:** Gerenciam o acesso e a temporização (leitura/escrita, confirmação, interrupção).

3. **PCIe (Peripheral Component Interconnect Express):** Barramento principal aual.
* Utiliza arquitetura **Serial** (conceito de faixa, todos os bits por uma conexão), que permite paralelismo entre faixas. É uma evolução do PCI, que era baseado em arquitetura de barramento compartilhado ou paralelo.

***

# Aula 4: Conceitos e Chamadas de Sistemas

## 1. Tipos de Sistemas Operacionais
Os SOs são classificados pelo ambiente e função que suportam:
### Grande Porte (Mainframes):
Foco em alta capacidade de E/S.
### Servidores:
Compartilham recursos em rede com múltiplos usuários
### Multiprocessadores:
Múltiplas CPUs ou núcleos em um único SO (Multinúcleo)
### Computadores Pessoais:
Suporte a multiprogramação e apoio ao usuário comum
### Portáteis (Mobile):
Gerenciamento de CPUs multinúcleo e diversos sensores
### Embarcados:
Controlam outros dispositivos.
Software na ROM.
Design simplificado, sem necessidade de proteção entre apps.
### Tempo Real:
Tempo é o fator chave.
Deve reagir em um intervalo fixo.
* **Crítico** não tolera atrasos
* **Não Crítico** tolera atrasos

## 2. Conceitos Fundamentais
### Processos:
Um **programa em execução**
* Possui **Espaço de Endereçamento**: memória que pode ler/escrever.
* Possui **Conjunto de Recursos**: registradores, arquivos abertos, alarmes.
* O SO gerencia proecssos via **Tabela de Processos** para manter o estado (contexto)
* Pode criar **Processos Filhos**: hierarquia
* É identificado por **PID** (Process ID) e o usuário por UID (User ID)

### Espaço de Endereçamento:
Conjunto de endereços que um processo pode referenciar.
* **Memória Virtual** permite que o programa utilize endereços virtuais, desvinculados da memória física, permitindo a execução de programas maiores que a RAM física.

### Arquivos:
Abstração para informações logicamente relacionadas, escondendo detalhes de E/S.
* Organizados em **Diretórios** (hierarquia de árvores).
* Possuem **Arquivos Especiais** (pseudo-arquivos que representam dispositivos de E/S).
* **Pipes** são pseudo-arquivos para conectar dois processos.

## 3. Chamadas de Sistemas (System Calls)
* É o **mecanismo** pelo qual um programa solicita um serviço ao SO.
* A execução de uma chamada segue:
1. O programa empilha os parâmetros e chama a rotina da biblioteca.
2. A rotina coloca o código da chamada em um registrador.
3. É executada uma instrução
**TRAP** para passar o controle do **Modo Usuário** para o **Modo Núcleo (SO)**.
4. O SO (Tratador de Chamada) despacha e trarta o serviço
5. O ocntrole é retornado ao programa.

### Modelo UNIX:
O SO tem poucas chamadas, e o interpretador de comandos (**shell**) usa as chamadas ```fork``` (cria proecsso) e ```execve``` (executa o programa) para gerenciar processos.

### Modelo Windows (API Win):
Orientado a **eventos**, mas também possui chamadas. A **API Win** (milhares de rotinas) desacopla o programador das chamadas de sistema do núcleo, permitindo à Microsoft mudá-las sem afetar o programador. O Windows não tem hierarquia de processos (criador e criatura são iguais).

***

# Aula 5: Estrutura de Sistemas Operacionais

## 1. Sistemas Monolíticos
* **Definição:** O SO é implementado como um **único programa** que roda totalmente no **modo núcleo**
* **Característica chave:** É **extremamente eficiente** porque qualquer rotina pode chamar qualquer outra, mas um erro pode **derrubar todo o SO**.

## 2. Sistemas de Camadas
* **Definição:** Estrutura que divide o SO em **camadas hierárquicas**, oned cada camada (nível) só pode interagir com as camadas adjacentes.
* **Característica chave:** O sistema MULTICS utilizou a ideia de **anéis concêntricos (Rings)**, onde quanto mais próximo do centro **(Ring 0)**, mais privilegiado o código é.

## 3. Microkernel (Micronúcleo)
* **Definição:** Estrutura que move o máximo de código possível para o **modo usuário** (drivers e servidores), deixando **somente o essencial no modo núcleo** (o microkernel).
* **Característica Chave:** Aumenta a **confiabilidade**, pois a falha de um módulo em modo usuário (como um driver) não compromete o sistema inteiro.

## 4. Modelo Cliente-Servidor
* **Definição:** Variação do microkernel que organiza os módulos como **servidores** (prestadores de serviçõs) e **clientes** (solicitadores de serviços).
* **Característica Chave:** A comunicação entre módulos é feita exclusivamente por **troca de mensagens**.

## 5. Máquinas Virtuais (VMs)
* **Definição:** Uma camada de software (**Monitor de Máquina Virtual - VMM** ou **Hipervisor**) que fornece aos SOs convidados uma **cópia exata do hardware subjacente**.
* **Característica Chave:** Permite que **múltiplos SOs diferentes** rodem isoladamente na mesma máquina física. O **Hipervisor Tipo 2** (o mais comum) roda sobre um Sistema Operacional Hospedeiro.

## 6. Exokernels
* **Definição:** Estrutura que foca na **divisão segura** dos recursos de hardware, expondo0os diretamente às aplicações (via **LibOS**), em vez de clonar o hardware.
* **Característica Chave:** Prioriza a **multiplexação segura** e permite que aplicações (usando bibliotecas) gerenciem seus próprios recursos, em vez de edpender de abstrações rígidas do kernel.

*** 

# Aula 6: Processos

## 1. O conceito de Processo

### Definição:
O conceito mais central em qualquer SO é o de **Processo**. Um processo é um **programa em execução**, uma **entidade ativa**.
* Um programa em disco é uma entidade passiva; quando ele é carregado na memória para execução, torna-se um ou mais processos.

### Multiprogramação:
É o mecanismo de trocas rápidas da **CPU real** entre processos para criar a **ilusão de paralelismo (pseudo paralelismo)**.

### Recursos de um Processo:
1. **Memória** - instruções e dados
2.  **CPU** - para executar instruções
3. **Dispositivos E/S**
4. **Arquivos** - gravar e recuperar informações

### Processos Especiais:
* **Daemons** - processos de segundo plano que não interagem com o usuário (monitoram um serviço).
* **init** - O primeiro processo do UNIX, que gera toda a **hierarquia de processos** (uma única árvore). O windows **não tem** hierarquia de processos.

### Tipos de Processos:
* **CPU-bound** - passa a maior parte do tempo utilizando a CPU.
* **I/O-bound** - passa a maior parte do tempo realizando operações ed Entrada/Saída.

## 2. Anatomia e Contexto do Processo
O **Contexto** de um processo são as informações necessárias para que ele possa ser suspenso e retomado:
* **Contexto de Hardware** - Conteúdo dos **registradores** (PC, SP, etc.). A **Troca de Contexto** é o ato de salvar os registradores de um processo e carregar os de outro.
* **Contexto de Software** - Informações administrativas, como **PID** (ID do Processo), **UID** (ID do Usuário), quotas e privilégios.
* **Espaço de Endereçamento** - Área de memória que contém o **Segmento de Texto** (código), **Segmento de Dados** (variáveis) e **Pilha de Execução**.

## 3. Ciclo de Vida do Processo
### Criação (Chamada de Sistema)
Um processo pode ser criado por inicialização do sistema, chamadas de sistema (```fork``` no UNIX), requisição do usuário ou início de tarefa em lote.
* No **UNIX**, ```fork``` cria um clone exato do pai; o filho usa ```execve``` para carregar um novo programa. Para economizar é comum usar o **Copy-on-wrute**, onde a cópia real da memória só é feita na primeira tentativa de escrita.
### Término
1. **voluntário** - Saida Normal/Erro
2. **involuntário** - Erro Fatal, como divisão por zero; ou Cancelamento por Outro Processo ex: ```kill``` no UNIX

## 4. Estados do Processo
Um processo pode estar em um de três estados:
1. **Em Execução** - Está usando a CPU naquele momento;
2. **Pronto** - Pode ser executado (está esperando a CPu), mas outro processo está em execução.
3. **Bloqueado** - Não pode ser executado, mesmo que a CPU esteja livre, pois está **aguardando um evento externo** (ex: E/S ou a saída de outro processo).
### Transições (Diagrama de Estados):
1. **Executando -> Bloqueado** - Ocorre quando o processo espera um recurso (E/S).
2. **Executando -> Pronto** - Ocorre por interrupção de *quantum* (tempo de execução) ou para dar parecla justa; causada pelo **Escalonador**.
3. **Pronto -> Executando** - Ocorre quando o Escalonador o escolhe para rodar.
4. **Bloqueado -> Pronto** - Ocorre quando o evento esperado (E/S) acontece.

## 5. Implementação e Modelagem
* **Implementação:** O SO gerencia os processos por meio da **Tabela de Processos (BCP - Bloco de Controle de Processos)**. Cada processo tem uma entrada (PCB) que armazena todo o seu contexto (Hardware, Software e Arquivos).
* **Modelagem da Multiprogramação:** A utilização da **CPU** ($U$) em um ambiente multiprogramado pode ser estimada probabilisticamente pela fórmula:

$$
\text{Utilização da CPU} = 1 - p^n
$$

Onde:
* **$U$** é a utilização da CPU.
* **$p$** é a fração de tempo que um processo passa esperando pr E/S
* **$n$** é o grau de multiprogramação (o número de processos na memória).

***

# Aula 7 : Escalonamento de Processos

## 1. Funções do Escalonamento
Em sistemas multiprogramados, o **Escalonador (Scheduler)** é o módulo do SO que escolhe qual processo, entre os que estão no estado **Pronto**, será o próximo a ser executado pela CPU.
### Objetivos:
Garantir um bom desempenho (tempo de resposta, vazão) e uso eficiente da CPU.
### Overhead:
A troca de processos (**Mudança de Contexto**) é uma tarefa custosa (overhead de tempo), pois exige salvar e carregar os registradores.
### Componentes:
* **Despachante (Dispatcher):** Responsável por salvar/recuperar o contexto e atualizar a Tabela de Processos (tarefa rápida).
* **Escalonador (Scheduler):** Escolhe a próxima tarefa (tarefa mais demorada).

## 2. Categorias de Escalonamento
### Preemptivo:
O processo em execução pode ser **interrompido à força** e perder o uso da CPU para outro processo (geralmente por expiração ed tempo ou chagaada de um processo de prioridade maior).
### Nâo Preemptivo:
O processo em execução **continua a rodar** até que:
1. ele termine
2. solicite uma operação ed E/S (seja bloqueado)
3. libere o processador explicitamente

## 3. Algoritmos de Escalonamento
Os algoritmos são adaptados a três categorias de sistemas, mas todos devem ser **Justos**, **Aplicadores da Política** e **Mantedores do Equilíbrio**.
### A. Sistemas em Lote (Batch)
Objetivo: Vazão, Tempo de Retorno, Utilização da CPU
1. **First-Come First-Served (FIFO)**
Não preemptivo.
Processos são executados na ordem de chagada.
Ineficiente se houver processos muito longos

2. **Shortest Job First (SFJ)**
Não preemptivo.
O menor processo da fila é executado primeiro;
Tende a ter o menor *turnaround* (tempo de espera + execução).
Requer que os tempos sejam conhecidos antecipadamente.

3. **Shortest Remaining Time Next (SRTN)**
Versão **preemptiva** do SFJ.
Se um novo processo chega com tempo restante menor que o do processo corrente, o novo processo assume a CPU.

### B. Sistemas Interativos
Objetivo: Resposta Rápida, Proporcionalidade
1. **Round-Robin (RR)**
Preemptivo (mais simples e usado).
Cada processo recebe um tempo fixo de execução chamado **quantum**.
Ao final, é suspenso e vai para o final da fila.
O tamanho do *quantum* é crítico (se muito pequeno, alta ineficiência por trocas; se muito longo, pior tempo de resposta).
2. **Prioridades**
Preemptivo.
Processos com maior prioridade são executados primeiro.
Risco de **inanição** (processos de baixa prioridade nunca são executados)
3. **Múltiplas Filas**
Um processo suspenso recebe um **quantum maior** e é alocado em uma **fila de prioridade mais baixa**.
Reduz trocas para processos longos.
4. **Garantido**
Garante que, dos ($n$) usuários, cada um receba $\frac{1}{n}$ do tempo da CPU.
5. **Loteria**
Distribui **bilhetes** que dão direito a recursos.
O escalonador sorteia um bilhete aleatóriamente.
Processos mais importantes recebem mais bilhetes.
6. **Fair-Share**
O escalonamento leva em conta o **dono do processo**, garantindo que o usuário receba sua fatia ed CPU, independente de quantos processos ele tenha.

### C. Sistemas em Tempo Real
Objetivo: Cumprimento de Prazos, Previsibilidade
* **Hard Real Time** - atrasos **não são tolerados** (ex: piloto automático)
* **Soft Real Time** - atrasos **ocasionais são tolerados** (ex: multimídia)
* **Tipos de Algoritmos** - Estáticos (decisões antes da execução) ou Dinâmicos (decisões em tempo de execução)

### Escalonadores Modernos (Linux)
Evoluiu de escalonadores baseados em epoch e tempo $O(n)$ e $O(1)$ para o **CFS (Completely Fair Scheduler)** (baseado em árvores Red-Black) e , mais recentemente, o **EEVDF (Earliest Eligible Virtual Deadline First Scheduling)** (pioridade baseada em tempo virtual).

***