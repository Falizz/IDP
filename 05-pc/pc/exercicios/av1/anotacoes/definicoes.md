# Definições Chave de Programação Concorrente

## I. Fundamentos e Hardware

- **Sistema Operacional (SO):**  
  É o software que fornece aos programas de usuário um modelo de computador melhor, mais simples e mais limpo (Máquina Estendida), e lida com o gerenciamento de todos os recursos (CPU, memória, etc.) de forma ordenada e controlada (**Gerenciador de Recursos**).

- **Máquina Estendida:**  
  Uma das duas principais funções do SO: esconde os detalhes primitivos e complexos do hardware, oferecendo uma interface mais simples e coerente (ex: arquivos com nomes).

- **Gerenciador de Recursos:**  
  Uma das duas principais funções do SO: controla o funcionamento do computador e gerencia a alocação de recursos (CPU, memória, E/S) de forma eficiente e justa.

- **Modo Núcleo (Kernel):**  
  Modo de execução da CPU onde o software (o SO) tem acesso total a todas as instruções e recursos.

- **Modo Usuário:**  
  Modo de execução com restrições a alguns recursos, usado por programas de aplicação.

- **MMU (Memory Management Unit):**  
  Unidade de hardware responsável por traduzir endereços virtuais (usados pelos programas) para endereços físicos (na memória RAM).

- **Interrupção:**  
  Um evento externo que faz a CPU parar a execução do programa atual e desviar para uma rotina de tratamento do SO. É o mecanismo primário de aviso do hardware para a CPU.

- **DMA (Direct Memory Access):**  
  Técnica que permite ao controlador de E/S controlar o fluxo de bits (transferência de dados) sem intervenção da CPU.

---

## II. Processos e Gerenciamento

- **Processo:**  
  O conceito mais central em qualquer SO: é um programa em execução, uma entidade ativa, que possui seu próprio espaço de endereçamento, registradores e recursos.

- **Multiprogramação:**  
  Mecanismo de trocas rápidas da CPU entre processos para criar a ilusão de paralelismo (pseudo-paralelismo).

- **Troca de Contexto:**  
  A mudança de um processo por outro na CPU, que envolve o SO salvando o conteúdo dos registradores do processo que sai e carregando os registradores do processo que entra.

- **Contexto (do Processo):**  
  Conjunto de informações (Hardware, Software e Espaço de Endereçamento) mantido na Tabela de Processos.

- **Espaço de Endereçamento:**  
  A área de memória que um processo pode referenciar. Contém:
  - Texto (código)  
  - Dados (variáveis)  
  - Pilha  

- **Memória Virtual:**  
  Técnica do SO que permite a execução de programas maiores do que a memória principal.

- **I/O-bound:**  
  Processo que passa a maior parte do tempo realizando operações de entrada e saída.

- **CPU-bound:**  
  Processo que passa a maior parte do tempo utilizando a CPU.

- **Chamada de Sistema (System Call):**  
  O mecanismo pelo qual um programa em modo usuário solicita um serviço ao SO (que é executado em modo núcleo).  
  A transição para o núcleo é feita pela instrução **TRAP**.

- **Tabela de Processos (BCP):**  
  Tabela mantida pelo SO (em modo núcleo) onde o contexto de cada processo é armazenado.

---

## III. Estados e Escalonamento

- **Em Execução:**  
  Estado do processo: está usando a CPU naquele momento.

- **Pronto:**  
  Estado do processo: pode ser executado, mas outro processo está executando (está esperando a CPU).

- **Bloqueado:**  
  Estado do processo: incapaz de ser executado, pois está aguardando um evento externo (ex: E/S ou a saída de outro processo).

- **Escalonador (Scheduler):**  
  Processo ou módulo do SO que escolhe qual será o próximo processo a ser executado, entre os que estão no estado Pronto.

- **Preemptivo:**  
  Categoria de escalonamento em que um processo pode ser interrompido à força (perder o uso da CPU) em favor de outro.

- **Não Preemptivo:**  
  Categoria de escalonamento em que o processo em execução continua até que ele termine, seja bloq
