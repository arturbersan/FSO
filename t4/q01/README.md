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
$ ./a.out `nomedeumarquivo` `timestamp`
```
Onde `nomedeumarquivo` é um arquivo (com ou sem o path), e o `timestamp` é uma string no formato:
`AAAAMMDDHHmm`, conforme descrito no roteiro do trabalho.

#### Caso de Teste Válido
Um caso de teste válido é executar o seguinte input:
```
$ ./a.out test_file.txt 201405020304
```
O arquivo `test_file.txt` deve estar na mesma pasta do binário criado, e está sendo enviado junto com as outras partes do trabalho.

## Limitações conhecidas
* A data de criação dos arquivos (birth time) não é alterada e nem apresentada. É possível checar a data de criação de um arquivo através do comando:
```
sudo debugfs -R 'stat usuario/caminho/q01/test_file.txt' /device_do_arquivo
```
exemplo:
```
sudo debugfs -R 'stat dguedes/Workspace/fso/FSO/t4/q01/test_file.txt' /dev/mapper/fedora-home
```
OBS: Dependendo do file-system utilizado, o comando mencionado acima não terá a data de criação `crtime`. Em file-systems com inode de tamanhos menores que 256bytes, o campo `crtime` não é utilizado.
Fontes:
- Ultima resposta:
```
http://unix.stackexchange.com/questions/50177/birth-is-empty-on-ext4/50184#50184
```
- Tabela do ext4 - O `crtime` é salvo no endereço 0x90, que em decimal é 144, um valor maior que 128, por exemplo
```
https://ext4.wiki.kernel.org/index.php/Ext4_Disk_Layout#Inode_Table
```
* A data de criação não está apresentada no programa (embora pudesse ser feito através do comando mencionado no item anterior) por decisão da dupla, pois o comando precisa de permissão de super-usuário.
* O arquivo de backup não tem exatamente os mesmos metadados do arquivo origem, pois o próprio `cp` modifica alguns desses meta-dados.
