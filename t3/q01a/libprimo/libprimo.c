#include "libprimo.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int gera_primo()
{
        int is_prime[70000];
        memset(is_prime, 1, sizeof is_prime);

        is_prime[1] = 0;

        int primes[70000];
        int total_primes = 1;
        int n = 50000;
        /* int n = 50000; */
        // sqrt(50000) < 70000

        for (int i=3; i < n; i+=2) {
                if (!is_prime[i])
                        continue;
                primes[total_primes-1] = i;
                total_primes++;
                int aux = n/i;
                for (int j=i; j<aux; j++) {
                        is_prime[j*i] = 0;
                }
        }

        srand ( time(NULL) );
        return primes[rand() % (total_primes-1)];
}

int testa_primo(int primo)
{
        if (!primo&1)
                return 0;
        else {
                int floor = sqrt(primo);
                if (!floor&1)
                        floor-=1;
                for (int i=floor; i>=2; i-=2) {
                        if (primo%floor == 0)
                                return 0;
                }
                return 1;
        }
}
