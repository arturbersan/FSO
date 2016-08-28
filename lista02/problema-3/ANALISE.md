# Análise das soluções

## Utilização
1. Compile o arquivo
```
$ make b
```
2. Rode o binário utilizando a biblioteca "time" e o arquivo "in" como input:
```
$ time cat in | ./a.out
```

## Resultados obtidos (utilizando "time", e o arquivo "in" como input)
### Item A
real    0m0.003s
user    0m0.002s
sys     0m0.003s


### Item B
real    0m0.005s
user    0m0.002s
sys     0m0.006s

### Item C
real    0m0.009s
user    0m0.001s
sys     0m0.010s

## Resultados obtidos (utilizando "time", e o arquivo "large_input" como input)
### Item A
real    0m0.006s
user    0m0.004s
sys     0m0.005s

### Item B
real    0m0.025s
user    0m0.007s
sys     0m0.026s

### Item C
real    0m0.029s
user    0m0.011s
sys     0m0.027s

## Análise
A não utilização de threads teve um desempenho melhor tanto com pequeno input (3x2 e 2x3) quanto com um input um pouco maior (20x20 e 20x20). Isto se deve ao fato de que as operações realizadas no problema são relativamente simples e que o input ainda não era grande o suficiente para fazer com que a utilização de threads valesse a pena. O overhead de criar threads, esperar, dar join em cada uma, dentre outras coisas, faz com que um tempo relativamente grande seja gasto gerenciando esse recurso.

A respeito da utilização de diversas threads X a utilização de threads num limite dado pelo /proc/cpuinfo, o desempenho da questão B ficou inferior para o arquivo "in" no que tange o tempo em que o binário estava executando (0.002s vs 0.001s). Isto se deve ao fato de uma menor alocação de threads. Por outro lado, o tempo em que o SO estava gerenciando as threads (sys) foi bem maior (0.006s vs 0.010s). Descobrir o número de núcleos do processador em tempo de execução pode ter tido um grande peso nesse resultado.

Ainda, para um maior input, a solução B teve desempenho quase igual em relação ao item sys (ou seja, a diferença diminuiu, provavelmente pela solução C usar menos threads), mas em relação ao user a solução B teve desempenho superior (0.007s vs 0.011s).

Logo, conclui-se que para o problema dado e para o conjunto de inputs utilizados a solução A embora seja a mais simples foi a solução mais rápida, a solução B a segunda mais rápida, e a solução C a de pior desempenho.
