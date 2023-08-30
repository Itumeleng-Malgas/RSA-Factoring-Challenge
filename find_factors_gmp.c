#include <stdio.h>
#include <gmp.h>

/*
 * find_factors - finds the smallest divisor of a given number.
 * @num_str: string representation of the number.
 */
void find_factors(const char *num_str)
{
    mpz_t num;
    mpz_init(num);
    
    /* Convert the string to GMP integer */ 
    mpz_set_str(num, num_str, 10);
    
    mpz_t factor;
    mpz_init(factor);

    mpz_t tmp;
    mpz_init(tmp);

    mpz_t sqrt_num;
    mpz_init(sqrt_num);
    mpz_sqrt(sqrt_num, num);

    if (mpz_even_p(num) != 0)
    {
        mpz_div_ui(tmp, num, 2);
        gmp_printf("%Zd=%Zd*2\n", num, tmp);
        return;
    }

    for (mpz_set_ui(factor, 3); mpz_cmp(factor, sqrt_num) <= 0; mpz_add_ui(factor, factor, 2))
    {
        if (mpz_divisible_p(num, factor) != 0)
        {
            mpz_div(tmp, num, factor);
            gmp_printf("%Zd=%Zd*%Zd\n", num, tmp, factor);
            return;
        }
    }

    gmp_printf("%Zd=%Zd*1\n", num, num);
    
    mpz_clear(num);
    mpz_clear(factor);
    mpz_clear(tmp);
    mpz_clear(sqrt_num);
}