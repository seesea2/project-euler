// Summation of primes
/*
	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
	Find the sum of all the primes below two million.

	Answer:
	142913828922
*/

#include "1_50.h"

void p10()
{
	const int kMaxRange = 2000000;

	uint64_t sum = 0;
	for (int i = 0; i < kMaxRange; ++i)
	{
		if (IsPrime(i))
			sum += i;
	}

	cout << sum << endl;
}