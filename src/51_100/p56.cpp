// Powerful digit sum
/*
A googol (10 power 100) is a massive number: one followed by one-hundred zeros; 
100 power 100 is almost unimaginably large: one followed by two-hundred zeros. 
Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a power b, where a, b < 100, what is the maximum digital sum?

	Answer:
	972
*/

#include "51_100.h"

void p56()
{
	const int POW_RANGE = 100;

	int max_sum = 0, sum = 0;
	BigNumber c;
	for (int a = 1; a < POW_RANGE; ++a)
	{
		for (int b = 1; b < POW_RANGE; ++b)
		{
			c = BigNumber(1);
			for (int i = 1; i <= b; ++i)
				c *= a;

			sum = 0;
			for (auto a = c.number_.begin(); a != c.number_.end(); ++a)
				sum += *a;
			max_sum = sum > max_sum ? sum : max_sum;
		}
	}

	cout << "Maximum digital sum : " << max_sum << endl;
}