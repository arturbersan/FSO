# FSO - Trabalho 1, Questão 2
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
Para remover os arquivos temporários e os executáveis
```
 $ make clean
```

#### Utilização
Para utilizar o programa, o usuário deverá inserir o nome do executável gerado, uma flag(opcional "-d" ou "-r"), e uma sequência de inteiros, como parâmetros da linha de comando. Por exemplo:
```
$ ./prog -r 1 20 3 40 5 60
$ ./prog -d 1 20 3 40 5 60
$ ./prog 1 20 3 40 5 60
```
O programa então irá apresentar o array como era antes e como ficou ápos a ordenação, apresentando o index e o valor do array no index.

#### Caso de Teste Válido
Um caso de teste válido para o programa seria, executar o binário com os seguintes argumentos:
```
$ ./prog -r 1 20 3 40 5 60
```

# Limitações conhecidas

O programa trabalha apenas com números positivos inteiros. Caso o usuário insira um valor que não seja um inteiro positivo, o programa não irá tratar o erro.
