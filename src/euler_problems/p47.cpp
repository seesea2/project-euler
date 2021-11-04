// Distinct primes factors
/*

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. 
What is the first of these numbers?


	Answer:  134043
*/

#include "1_99.h"

bool P47()
{
	try
	{
		int num = 644;
		set<uint64_t> factors[] = {
			GetFactors(num),
			GetFactors(num + 1),
			GetFactors(num + 2),
			GetFactors(num + 3)};
		int size[4] = {3, 3, 3, 0};
		do
		{
			cout << "check: " << num << endl;
			factors[3] = GetFactors(num + 3);
			size[3] = 0;
			for (auto &factor : factors[3])
			{
				if (IsPrime(factor))
					size[3] += 1;
			}
			if (size[0] == 4 && size[1] == 4 && size[2] == 4 && size[3] == 4)
			{
				cout << "Answer: " << num << endl;
				break;
			}

			factors[0] = factors[1];
			factors[1] = factors[2];
			factors[2] = factors[3];
			size[0] = size[1];
			size[1] = size[2];
			size[2] = size[3];
			num++;

		} while (1);

		return true;
	}
	catch (...)
	{
		return false;
	}
}
