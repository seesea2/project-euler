// 10001st prime
/*
	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
	we can see that the 6th prime is 13.

	What is the 10001st prime number?

	Answer:
	104743
*/

#include "1_99.h"

bool P7()
{
	try
	{
		uint64_t v = 1;
		int ind = 0;

		do
		{
			if (IsPrime(v))
			{
				++ind;
				if (ind == 10001)
					break;
			}
			++v;
		} while (1);

		cout << "Answer: " << v << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}