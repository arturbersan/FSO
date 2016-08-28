## Sistema Operacional Utilizado:
Fedora Linux 24x86_64 - Kernel 4.6.3-300

## Ambiente de Desenvolvimento:
Computadores pessoais. Utilizamos o Linux, Makefile, git, vim e valgrind.

## Instruções
#### Compilando
Cada item tem sua instrução no makefile. Para compilar o item 3 da questão 3 (parte C da questão), escreva:
```
$ make c
```

#### Utilização
Um arquivo de input pronto está localizado na mesma pasta do Makefile, e tem o nome de "in". Para utilizar, passe o conteúdo do arquivo "in" para o binário gerado:
```
$ cat in | ./a.out
```
O binário será então utilizado com o conteúdo do arquivo "in".
Também é possível utilizar o arquivo "large_input", que apresenta uma matriz maior que a presente no arquivo "in".

Caso seja necessário a utilização de input via IO, os inputs esperados são os seguintes:
> 
  Número de linhas da matriz A
  Número de colunas da matriz A
  Número de linhas da matriz B
  Número de colunas da matriz B
  Itens da matriz A
  Itens da matriz B

O programa responderá então com as matrizes entradas (A e B) e o resultado de AxB.

# Output - valgrind (usando os inputs presentes em "in")
## Utilização

1. Compile a questão:
```
$ make a
```
2. Utilize o binário no valgrind, utilizando o arquivo "in" de input:
```
$ valgrind ./a.out < in
```
Também é possível utilizar o arquivo "large_input", que apresenta uma matriz maior que a presente no arquivo "in".

#### Item A - Resultado
==14122== HEAP SUMMARY:
==14122==     in use at exit: 0 bytes in 0 blocks
==14122==   total heap usage: 16 allocs, 16 frees, 5,392 bytes allocated
==14122==
==14122== All heap blocks were freed -- no leaks are possible

#### Item B - Resultado
==10623== LEAK SUMMARY:
==10623==    definitely lost: 0 bytes in 0 blocks
==10623==    indirectly lost: 0 bytes in 0 blocks
==10623==      possibly lost: 0 bytes in 0 blocks
==10623==    still reachable: 1,584 bytes in 4 blocks
==10623==         suppressed: 0 bytes in 0 blocks

#### Item C - Resultado
==10644== LEAK SUMMARY:
==10644==    definitely lost: 0 bytes in 0 blocks
==10644==    indirectly lost: 0 bytes in 0 blocks
==10644==      possibly lost: 1,632 bytes in 6 blocks
==10644==    still reachable: 0 bytes in 0 blocks
==10644==         suppressed: 0 bytes in 0 blocks

# Limitações conhecidas
- O valgrind alerta que talvez alguns blocos de memória tenham sido perdidos na solução C
- O input não é grande o suficiente para fazer com que as soluções que usem thread tenham chance de ter melhor desempenho que a solução que não use.
