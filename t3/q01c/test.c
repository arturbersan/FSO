#include <stdio.h>
#include <dlfcn.h>

int main()
{
        void* sdl_library = dlopen("libprimo/libprimo.so", RTLD_LAZY);
        if (sdl_library == NULL) {
                printf("Não foi possível abrir o arquivo\n");
        } else {

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
        }
        return 0;
}
