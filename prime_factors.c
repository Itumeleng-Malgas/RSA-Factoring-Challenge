#include <stdio.h>
#include <gmp.h>

void find_prime_factors(const char *num_str) {
    mpz_t n;
    mpz_t divisor;
    mpz_t quotient;  // Temporary variable for division
    mpz_init(n);
    mpz_init(divisor);
    mpz_init(quotient);

    // Convert input string to GMP integer
    mpz_set_str(n, num_str, 10);

    // Print the original number
    gmp_printf("%Zd=", n);

    // Find and print prime factors
    mpz_set_ui(divisor, 2);
    int first_factor = 1; // Flag to handle the multiplication symbol
    while (mpz_cmp_ui(n, 1) > 0) {
        while (mpz_divisible_p(n, divisor)) {
            if (!first_factor) {
                gmp_printf("*");
            }
            gmp_printf("%Zd", divisor);
            mpz_divexact(quotient, n, divisor);
            mpz_set(n, quotient);
            first_factor = 0;
        }
        mpz_nextprime(divisor, divisor);
    }
    gmp_printf("\n");

    // Clear GMP variables
    mpz_clear(n);
    mpz_clear(divisor);
    mpz_clear(quotient);
}