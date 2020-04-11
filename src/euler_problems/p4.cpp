// Largest palindrome product
/*
	A palindromic number reads the same both ways. 
	The largest palindrome made from the product 
	of two 2-digit numbers is 9009 = 91 x 99.

	Find the largest palindrome made from the product of two 3-digit numbers.

	Answer:
	906609
*/

#include "1_99.h"

bool P4()
{
	try
	{

		uint64_t a, b, c, max_v = 0;
		string str, rStr;

		for (a = 999; a > 1; --a)
		{
			for (b = 999; b > 1; --b)
			{
				c = a * b;
				if (c <= max_v)
					continue;

				str = to_string(c);
				rStr = str;
				reverse(rStr.begin(), rStr.end());
				if (str == rStr)
					max_v = c;
			}
		}

		cout << "Largest palindrome product of two 3-digit numbers : " << max_v << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
