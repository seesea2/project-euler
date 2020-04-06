//Summation of primes
/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include "../header.h"
#include "../math_functions.h"

void Problem10()
{
	const int kMaxRange = 2000000;

	double sum = 0;
	for(int i = 0; i < kMaxRange; ++i)
	{
		if(IsPrime(i))
			sum += i;
	}

	cout << sum << endl;
}