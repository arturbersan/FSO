# FSO - Trabalho 5, Questão 1
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
Para compilar, entre com o seguinte comando no terminal:
```
 $ make all
```
Para remover os arquivos temporários e os executáveis:
```
 $ make clean
```
#### Utilização
Após ser compilado, o binário pode ser executado através do comando
```
$ ./a.out `numero_de_threads`
```
Onde `numero_de_threads` deve ser um inteiro positivo, de preferencia entre 1 e 10.

#### Caso de Teste Válido
Um caso de teste válido é executar o seguinte input:
```
$ ./a.out 10
```

## Limitações conhecidas
* Caso a interrupção com `ctrl+C` ocorra antes do término das threads, ainda assim será necessário aguardar que todas completem suas tarefas.
* Se o comando `ctrl+C` não for executado, o programa não termina.
