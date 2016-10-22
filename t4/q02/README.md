# FSO - Trabalho 4, Questão 2
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
$ ./a.out `caminhodoarquivo` `substring` `quantidadesdearquivos`
```
Onde `caminhodoarquivo` é um path dentro da árvore de diretórios do sistema, a `substring` é uma string que representa uma subtring a ser encontrada no nome do arquivo e `quantidadesdearquivos` é um numero inteiro que representa a quantidade de arquivos a serem printados.

#### Caso de Teste Válido
Um caso de teste válido é executar o seguinte input:
```
$ ./a.out . test 1
$ ./a.out . test 2
$ ./a.out . test 3
$ ./a.out . test 4
```
O programa irá fazer uma busca no diretório atual e procurar os arquivos que tenha a substring "test" no seu nome.

## Questão discursiva
O FHS é o sistema de arquivos hierárquico padrão que define os principais diretórios e seus respectivos conteúdos em um SO da família Unix. Para ter acesso as pastas tipicamente encontradas na raiz de um sistema de arquivos UNIX, basta começar por "/" que é o path inicial do diretório raiz.

## Limitações conhecidas
Caso o usuário passe um caminho que não exista na árvore de diretórios, o programa não irá informar essa ocorrência.
