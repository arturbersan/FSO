int gera_primo();
int testa_primo(int);

#include <stdio.h>

int main()
{
        printf("Primo gerado: %d \n", gera_primo());
        printf("15 ");
        if (testa_primo(15)) {
                printf("é primo!\n");
        } else {
                printf("não é primo.\n");
        }

        printf("39 ");
        if (testa_primo(39)) {
                printf("é primo!\n");
        } else {
                printf("não é primo.\n");
        }
        return 0;
}
