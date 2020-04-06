//Quadratic primes
/*
Euler discovered the remarkable quadratic formula:

(n power 2) + n + 41

It turns out that the formula will produce 40 primes for the consecutive integer values 0¡Ün¡Ü39. 
However, when n=40,(40 power 2) + 40 + 41 = 40(40+1)+41 is divisible by 41, and certainly 
when n=41,(41 power 2) + 41 + 41 is clearly divisible by 41.

The incredible formula (n power 2) - 79n + 1601 was discovered, 
which produces 80 primes for the consecutive values 0¡Ün¡Ü79. 
The product of the coefficients, -79 and 1601, is ?126479.

Considering quadratics of the form:

    (n power 2) + an + b, where |a|<1000 and |b|<=1000

where |n| is the modulus/absolute value of n e.g. |11|=11 and |-4|=4

Find the product of the coefficients, a and b, for the quadratic expression 
that produces the maximum number of primes for consecutive values of n, starting with n=0.
*/

#include "../header.h"
#include "../math_functions.h"

void Problem27() {
	int best_a = 0, best_b = 0;					//final rslt :  a = -61  b = 971     a*b = -59231
	int max_prime_qty = -1, prime_qty = 0;
	double expression_rslt = 0.0;

	int a, b;
	for(a = -999; a <= 999; ++a)
	{
		for(b = -999; b <= 999; ++b)
		{
			//cout << a << " vs " << b << endl;
			int n = 0; 
			prime_qty = 0;
			while(1)
			{
				expression_rslt = n * n + a * n + b;
				if(expression_rslt > 0 && IsPrime(expression_rslt))
					++prime_qty;
				else
					break;
				++n;
			}

			if(prime_qty > max_prime_qty)
			{
				max_prime_qty = prime_qty;
				best_a = a, best_b = b;
			}
		}
	}

	cout << "a: " << best_a << "   b: " << best_b << endl;
	cout << "Product of the coefficients : " << best_a * best_b << endl << endl;;
}
