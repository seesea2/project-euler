// Prime permutations
/*
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, 
is unusual in two ways: 
(i) each of the three terms are prime, and, 
(ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, 
exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

	Answer:	2969-6299-9629
*/

#include "1_99.h"

bool P49()
{
	try
	{
		vector<int> prime_nums;
		for (auto i = 1000; i <= 9999; ++i)
		{
			if (!IsPrime(i))
				continue;
			prime_nums.push_back(i);
		}

		for (auto &n1 : prime_nums)
		{
			for (auto &n2 : prime_nums)
			{
				if (n1 >= n2)
					continue;
				for (auto &n3 : prime_nums)
				{
					if (n2 >= n3)
						continue;
					if (n2 - n1 != n3 - n2)
						continue;

					string n1_str = to_string(n1);
					string n2_str = to_string(n2);
					string n3_str = to_string(n3);
					sort(n1_str.begin(), n1_str.end());
					sort(n2_str.begin(), n2_str.end());
					sort(n3_str.begin(), n3_str.end());
					if (n1_str != n2_str || n2_str != n3_str)
						continue;

					cout << "Answer: " << n1 << n2 << n3 << endl;
				}
			}
		}

		return true;
	}
	catch (...)
	{
		return false;
	}
}
