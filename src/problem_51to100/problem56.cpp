//Powerful digit sum
/*
A googol (10 power 100) is a massive number: one followed by one-hundred zeros; 
100 power 100 is almost unimaginably large: one followed by two-hundred zeros. 
Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a power b, where a, b < 100, what is the maximum digital sum?
*/

#include "../header.h"
#include "../big_number_class.h"


void Problem56()
{
	const int POW_RANGE = 100;

	int rslt = 0;
	BigNumberC c;

	for(int a = 1; a < POW_RANGE; ++a)
	{
		for(int b = 1; b < POW_RANGE; ++b)
		{
			c = BigNumberC(a);

			for(int i = 1; i <= b; ++i)
				c.Multiply(a);

			rslt = max(rslt, c.GetDigitsSum());
		}
	}

	cout << "Maximum digital sum : " << rslt << endl;
}