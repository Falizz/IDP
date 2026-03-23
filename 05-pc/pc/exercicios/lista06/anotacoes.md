Para encerrar um processo em execução, é possível enviar sinais para ele. O comando
`kill` é utilizado para enviar sinais para processos em execução. Cada sinal tem um
significado diferente, e estes são utilizados para controlar o comportamento do
processo.

Caso você esteja executando um programa em um terminal, é possível enviar sinais
para o mesmo pressionando alguns atalhos do teclado. Exemplos:

- `Ctrl + C`: Envia o sinal de interrupção (SIGINT) para o processo em execução.
- `Ctrl + Z`: Envia o sinal de suspensão (SIGTSTOP) para o processo em execução.
- `Ctrl + \`: Envia o sinal de término (SIGQUIT) para o processo em execução.
- `Ctrl + D`: Envia o sinal de fim de arquivo (EOF) para o processo em execução.

Retomar execução do processo após suspensão (`Crtl + Z`)
- bg
- fg

Iniciar a execução do processo em segundo plano
- ./proecsso &
