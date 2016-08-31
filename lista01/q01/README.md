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
Para remover os arquivos temporários e os executáveis
```
 $ make clean
```
#### Utilização
Um arquivo de input pronto está localizado na mesma pasta do Makefile, e tem o nome de "input.txt". Para utilizar, passe o conteúdo do arquivo "input.txt" para o binário gerado:
```
$ ./prog < input.txt
```
O binário será então utilizado com o conteúdo do arquivo "input.txt".
Também é possível insirir os dados, de acordo como se pede no programa.

Caso se os pontos dados pela entrada formarem um triangulo, o programa responderá com o tamanho de cada lado, com seu perimetro e área. Caso contrário, será imprimido na tela:
"Is not a triangle".

#### Caso de Teste Válido
Um caso de teste válido seria executar o binário com os seguintes argumentos:
```
y
3 6
1 2
5 1
y
0 5
5 5
3 5
n
```

## Limitações conhecidas

- Erros de precisão podem ocorrer, por se tratarem de variáveis de ponto flutuante
- As variáveis tem um limite de tamanho (diferente do BigInteger do Java, por exemplo)
