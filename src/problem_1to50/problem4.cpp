//Largest palindrome product
/*
A palindromic number reads the same both ways. The largest palindrome made from the product 
of two 2-digit numbers is 9009 = 91 ¡Á 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include "../header.h"

void Problem4()
{
	int a, b;
	long c, max_v = 0;
	int cur_a, cur_b;

	char str[11];
	int i, n;


	for(a = 999; a > 1; --a)
	{
		for(b = 999; b > 1; --b)
		{
			c = a * b;
			if(c < max_v)
				continue;

			memset(str, '\0', sizeof(str));
			_itoa_s(c, str, 10);

			n = strlen(str);
			for(i = 0; i <= n/2; ++i)
			{
				if(str[i] != str[n-1 - i])
					break;
			}
			if( i > n/2)
			{
				cur_a = a;
				cur_b = b;
				max_v = c;
			}
		}
	}

	cout << "Largest palindrome product of two 3-digit numbers : " << max_v << endl;
}