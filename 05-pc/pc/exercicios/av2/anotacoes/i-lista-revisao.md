# Exercícios de Detecção de Deadlocks - Modelo de Holtercícios de Detecção de Deadlocks - Modelo de Holt

---

## I - Primeiro Exercício de Detecção de Deadlocksção de Deadlocks

### Código dos Processos

| Processo A | Processo B | Processo C |
|---|---|---|
| requisita(K) | requisita(L) | requisita(M) |a(L) | requisita(M) |
| requisita(L) | requisita(K) | requisita(L) || requisita(L) | requisita(K) | requisita(L) |
| libera(L) | requisita(M) | libera(L) |ta(M) | libera(L) |
| libera(K) | libera(M) | libera(M) || libera(K) | libera(M) | libera(M) |
| | libera(K) | | | |
| | libera(L) | | | |

### Sequência de Execuçãocia de Execução

1. A requisita Ksita K
2. A requisita La L
3. B requisita La L
4. A libera L
5. C requisita Msita M
6. A libera Ka K
7. C requisita Lsita L
8. B requisita Ksita K
9. B requisita Msita M
10. C libera L10. C libera L
11. C libera M
12. B libera M12. B libera M
13. B libera K B libera K
14. B libera L14. B libera L

### Análise de Estados### Análise de Estados

**Tarefa:** Represente cada estado do sistema após cada evento utilizando o Modelo de Detecção de Deadlocks apresentado por Holt, indicando se há ocorrência de deadlock.**Tarefa:** Represente cada estado do sistema após cada evento utilizando o Modelo de Detecção de Deadlocks apresentado por Holt, indicando se há ocorrência de deadlock.

> **Obs:** Não há submissão de resposta nesta questão.a questão.

---

## II - Segundo Exercício de Detecção de DeadlocksDeadlocks

### Código dos Processos### Código dos Processos

| Processo A | Processo B | Processo C || Processo A | Processo B | Processo C |
|---|---|---|
| requisita(K) | requisita(L) | requisita(L) |) | requisita(L) | requisita(L) |
| requisita(L) | requisita(M) | requisita(K) |) | requisita(M) | requisita(K) |
| libera(L) | libera(M) | requisita(M) |) | libera(M) | requisita(M) |
| libera(K) | libera(L) | libera(M) | libera(L) | libera(M) |
| | | libera(K) |ra(K) |
| | | libera(L) |(L) |

### Sequência de Execuçãocia de Execução

1. A requisita K K
2. A requisita Lita L
3. B requisita Lita L
4. A libera L L
5. C requisita L5. C requisita L
6. A libera K
















---> **Obs:** Não há submissão de resposta nesta questão.**Tarefa:** Represente cada estado do sistema após cada evento utilizando o Modelo de Detecção de Deadlocks apresentado por Holt, indicando se há ocorrência de deadlock.### Análise de Estados14. C libera L13. C libera K12. C libera M11. C requisita M10. C requisita K9. B libera L8. B libera M7. B requisita M7. B requisita M
8. B libera M
9. B libera L
10. C requisita K
11. C requisita M
12. C libera M
13. C libera K
14. C libera L

### Análise de Estados

**Tarefa:** Represente cada estado do sistema após cada evento utilizando o Modelo de Detecção de Deadlocks apresentado por Holt, indicando se há ocorrência de deadlock.

> **Obs:** Não há submissão de resposta nesta questão.

---