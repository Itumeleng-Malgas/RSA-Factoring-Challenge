#include <stdio.h>

/*
 * find_factors - find the smallest divisor N.
 * @N: given integer.
 * Return: 0 if the number is prime.
 */
int find_factors(long int N)
{
	long int factor;

	if (N % 2 == 0)
	{
		printf("%lu=%lu*%i\n", N, N / 2, 2);
		return (0);
	}

	factor = 3;
	while (factor * factor <= N)
	{
		if (N % factor == 0)
		{
			printf("%lu=%lu*%lu\n", N, N / factor, factor);
			return (0);
		}
		else
			factor += 2;
	}

	printf("%lu=%lu*%i\n", N, N, 1);
	return (0);
}