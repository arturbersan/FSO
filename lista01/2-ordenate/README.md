## Sistema Operacional Utilizado:
Ubunto Linux - x86_64 Kernel 3.13.0-32-generic

## Ambiente de Desenvolvimento:
Computadores pessoais. Utilizamos o Linux, Makefile, git e vim.

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

# Limitações conhecidas

O programa trabalha apenas com números positvos inteiros. Caso o usuário insira um valor que não seja um inteiro positvo, o programa não irá tratar o erro.
