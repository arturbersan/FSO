# FSO - Trabalho 1, Questão 3
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
 $ gcc -o prog pointer.c
```

#### Utilização
Para utilizar o programa, o usuário deverá rodar o executável. Por exemplo:
```
$ ./prog
```
Depois deverá ser inserido uma string, como é apresentado pelas instruções do programa.

O programa então irá apresentar as impressões que o enunciado pede na questão.

#### Caso de Teste Válido
Um caso de teste válido seria, ao executar o binário, inserir a string `myfirststring`. Os resultados corretos são então mostrados em seguida.

# Limitações conhecidas
- Dependendo do tamanho das strings, a diretiva `strcat` pode causar erro de runtime
