#include <stdio.h>
#include <math.h>

/*
 * find_factors - finds the smallest divisor of a given number.
 * @num: operant to find factors for.
 */
void find_factors(unsigned long long int num)
{
	unsigned long long int factor;

	if (num % 2 == 0)
	{
		printf("%llu=%llu*%i\n", num, num / 2, 2);
		return;
	}

	for (factor = 3; factor <= sqrt(num); factor += 2)
	{
		if (num % factor == 0)
		{
			printf("%llu=%llu*%llu\n", num, num / factor, factor);
			return;
		}
		else
			factor += 2;
	}

	printf("%llu=%llu*%i\n", num, num, 1);
}