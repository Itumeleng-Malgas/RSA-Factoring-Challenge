#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

uint64_t *factorize(uint64_t N) {
    uint64_t sqrt_N = (uint64_t)sqrt(N);
    
    uint64_t *factors = (uint64_t *)malloc(sizeof(uint64_t) * (10));
    if (!factors) {
        perror("Memory allocation error");
        return (NULL);
    }
    int count = 0;

    for (uint64_t factor = 1; factor <= sqrt_N; ++factor) {
        if (N % factor == 0 && !(factor == N || factor == 1)) {
            factors[count++] = factor;
            if (factor != N / factor) {
                factors[count++] = N / factor;
            }
        }
    }

    return factors;
}