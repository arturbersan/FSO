# FSO - Trabalho 4, Questão 1
>  Alunos: Dylan Guedes e Artur Bersan

>  Matrículas: 12/0115727 e 14/0016813

## Sistema Operacional Utilizado
> Ubuntu Linux - x86_64 Kernel 3.13.0-32-generic

> Linux Fedora 24 - x86_64 Kernel 4.6.3-300

## Ambiente de Desenvolvimento
> Computadores pessoais. Utilizamos o Linux, Makefile, gcc, pthread, git, valgrind e vim.

## Questões

## Instruções
#### Compilando
Para compilar, digite na mesma pasta que o Makefile
```
 $ make all
```
Para remover os arquivos temporários e os executáveis
```
 $ make clean
```
#### Utilização
Após ser compilado, o binário pode ser executado através do comando
```
$ ./a.out `nomedeumarquivo` `timestamp`
```
Onde `nomedeumarquivo` é um arquivo (com ou sem o path), e o `timestamp` é uma string no formato:
`AAAAMMDDHHmm`, conforme descrito no roteiro do trabalho.

#### Caso de Teste Válido
Um caso de teste válido é executar o seguinte input:
```
$ ./a.out test_file.txt 201405020304
```
O arquivo `test_file.txt` deve estar na mesma pasta do binário criado.

## Limitações conhecidas
