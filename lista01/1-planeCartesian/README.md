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
Um arquivo de input pronto está localizado na mesma pasta do Makefile, e tem o nome de "input.txt". Para utilizar, passe o conteúdo do arquivo "input.txt" para o binário gerado:
```
$ ./prog < input.txt
```
O binário será então utilizado com o conteúdo do arquivo "input.txt".
Também é possível insirir os dados, de acordo como se pede no programa.

Caso se os pontos dados pela entrada formarem um triangulo, o programa responderá com o tamanho de cada lado, com seu perimetro e área. Caso contrário, será imprimido na tela:
"Is not a triangle".

# Limitações conhecidas

Escrever essa parte
