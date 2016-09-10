# FSO - Trabalho 2, Questão 1
>  Alunos: Dylan Guedes e Artur Bersan

>  Matrículas: 12/0115727 e 14/0016813

## Sistema Operacional Utilizado
> Ubuntu Linux - x86_64 Kernel 3.13.0-32-generic

> Linux Fedora 24 - x86_64 Kernel 4.6.3-300

## Ambiente de Desenvolvimento
> Computadores pessoais. Utilizamos o Linux, Makefile, gcc, pthread, git, valgrind e vim.

## Instruções
#### Compilando
Para compilar, basta rodar o comando:
```
 $ make
```
Para remover os arquivos temporários e os executáveis
```
 $ make clean
```
#### Utilização
Após ser compilado, o binário pode ser executado através do comando
```
$ ./q01
```
O código cria então um processo filho, e aguarda por um sinal. O processo filho dormirá por 5 segundos, e então mandará para o processo pai um sinal do tipo  `SIGALRM`. O pai aguarda o filho através do comando `pause()`. Após, o pai espera a conclusão do processo filho com a utilização do comando `wait()`. OBS: O ultimo passo (aguardo do processo filho através do comando `wait()`, quando não utilizado, faz com que o programa não retorne o status de sucesso. Isso pode ser confirmado com a retirada da linha e execução do programa, seguido pelo comando:
```echo $?```
Que printa o status do ultimo programa executado. Após o uso do `wait()`, o status se tornou 0, o que significa sucesso.

#### Caso de Teste Válido
A questão não apresenta interação com o usuário (logo não são necessários casos de teste).

## Limitações conhecidas
