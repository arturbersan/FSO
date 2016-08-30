#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  double number1 = 7.3, number2;
  char s1[100], s2[100];
  double *dPtr;
  dPtr = &number1;
  printf("Conteúdo de dPtr: %lf\n", *dPtr);
  number2 = *dPtr;
  printf("Conteúdo de number2: %lf\n", number2);
  printf("Endereço de number1: %p\n", &number1);
  printf("Endereço de dPtr: %p\n", dPtr);
  if(&number1==dPtr)
    printf("Valor de endereço de dPtr e number1 são iguais\n");
  else
    printf("Valor de endereço de dPtr e number1 são diferentes\n");
  printf("Insira alguma string:\n");
  scanf("%s",s1);
  strcpy(s2,s1);
  if(strcmp(s1,s2)==0)
    printf("String s1 e s2 iguais\n");
  else if(strcmp(s1,s2)>0)
    printf("s1 maior que s2\n");
  else
    printf("s1 menor que s2\n");


  strcat(s2,s1);
  printf("String anexada %s\n",s2);
  printf("A execução anterior pode dar problema, caso a anexagem estourar a memória, ou seja, passe de 100 itens\n");

  return 0;
}
