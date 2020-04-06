//10001st prime
/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include "../header.h"
#include "../math_functions.h"


void Problem7()
{
	double prime_v = 1;
	int ind = 0;

	do
	{
		if(IsPrime(prime_v))
		{
			++ind;
			if(ind == 10001)
				break;
		}
		++prime_v;
	}while(1);

	cout << prime_v << endl;
}