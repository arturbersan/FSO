# FSO - Trabalho 3, Questão 1, Item B
>  Alunos: Dylan Guedes e Artur Bersan

>  Matrículas: 12/0115727 e 14/0016813

## Sistema Operacional Utilizado
> Ubuntu Linux - x86_64 Kernel 3.13.0-32-generic

> Linux Fedora 24 - x86_64 Kernel 4.6.3-300

## Ambiente de Desenvolvimento
> Computadores pessoais. Utilizamos o Linux, Makefile, gcc, pthread, git, valgrind e vim.

## Instruções
#### Compilando
Para compilar utilizando a versão dinâmica da biblioteca, basta rodar o comando:
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
$ ./app
```
Um número primo aleatório será então gerado e mostrado na tela, e será analisado se um dado número é primo (e é), e se outro dado número não é primo (e não é).

#### Caso de Teste Válido
O usuário não interage com a aplicação. Embora os resultados do número primo gerado mudem, pois é aleatório, o usuário não tem poder sobre o resultado que será apresentado.

## Limitações conhecidas
Números primos maiores que 50000 não podem ser gerados. A função rand() é pseudoaleatória, se o binário for executado várias vezes em um curto intervalo de tempo o resultado vai ser o mesmo.
