# FSO - Trabalho 1, Questão 1
>  Alunos: Dylan Guedes e Artur Bersan

>  Matrículas: 12/0115727 e 14/0016813

## Sistema Operacional Utilizado
> Ubuntu Linux - x86_64 Kernel 3.13.0-32-generic

> Linux Fedora 24 - x86_64 Kernel 4.6.3-300

## Ambiente de Desenvolvimento
> Computadores pessoais. Utilizamos o Linux, Makefile, git, valgrind e vim.

## Instruções
#### Compilando
Para compilar, basta rodar o comando:
```
$ make
```

#### Utilização
 Para utilizar o programa, o usuário deverá inserir o nome do executável gerado, o tamanho do array e em seguida, uma sequencia de inteiros como parâmetros da linha de comando. Por exemplo:
```
$ ./prog 4 3 1 7 4
```
O programa irá apresentar a quantidade de inputs os valores dos inputs, o array 'w' antes e depois da inicialização, as comparações entre os elementos, o maior valor e a posição dele.

#### Caso de Teste Válido
Um caso de teste válido para o programa seria, executar o binário com os seguintes argumentos:
```
$ ./prog 6 1 20 3 40 5 60
```
# Limitações conhecidas
Caso o usuário digitar um número muito grande, irá causar overflow.

# Análise

## Respondendo a questão "Por que precisamos n(n-1)/2 em vez de n^2 threads?
Para responder a essa pergunta, primeiro temos que perceber que o algortimo prega uma combinação em que o valor de 'P' =  2, seguindo a formula:
```
n!/p!*(n-p)!
```
##Simplificando:
###Passo 1:
```
n!/2!*(n-2)!
```
###Passo 2:
```
(n*(n-1)*(n-2)!)/(n-2)!*2!
```
###Passo 3:
Corta n-2! com n-2! e fica:
```
n(n-1)/2
```

## Análise
A não utilização de threads teve um desempenho melhor tanto com pequeno input (3x2 e 2x3) quanto com um input um pouco maior (20x20 e 20x20). Isto se deve ao fato de que as operações realizadas no problema são relativamente simples e que o input ainda não era grande o suficiente para fazer com que a utilização de threads valesse a pena. O overhead de criar threads, esperar, dar join em cada uma, dentre outras coisas, faz com que um tempo relativamente grande seja gasto gerenciando esse recurso.

A respeito da utilização de diversas threads X a utilização de threads num limite dado pelo /proc/cpuinfo, o desempenho da questão B ficou inferior para o arquivo "in" no que tange o tempo em que o binário estava executando (0.002s vs 0.001s). Isto se deve ao fato de uma menor alocação de threads. Por outro lado, o tempo em que o SO estava gerenciando as threads (sys) foi bem maior (0.006s vs 0.010s). Descobrir o número de núcleos do processador em tempo de execução pode ter tido um grande peso nesse resultado.

Ainda, para um maior input, a solução B teve desempenho quase igual em relação ao item sys (ou seja, a diferença diminuiu, provavelmente pela solução C usar menos threads), mas em relação ao user a solução B teve desempenho superior (0.007s vs 0.011s).

Logo, conclui-se que para o problema dado e para o conjunto de inputs utilizados a solução A embora seja a mais simples foi a solução mais rápida, a solução B a segunda mais rápida, e a solução C a de pior desempenho.
