// Consecutive prime sum
/*
By replacing the 1st digit of the 2-digit number *3, 
it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, 
are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, 
this 5-digit number is the first example having seven primes among the ten generated numbers, 
yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. 
Consequently 56003, being the first member of this family, 
is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number 
(not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

	Answer:	121313	

*/

#include "1_99.h"

bool P51()
{
	try
	{
		vector<string> prime_nums;
		// eight prime value
		for (int digits = 3; digits <= 6; ++digits)
		{
			cout << "preparing prime number list, digits:" << digits << endl;
			prime_nums.clear();

			uint64_t range_min = pow(10, digits - 1);
			uint64_t range_max = pow(10, digits);
			for (uint64_t num = range_min; num < range_max; num++)
			{
				if (IsPrime(num))
					prime_nums.push_back(to_string(num));
				cout << "prime num:" << num << endl;
			}
			cout << "prime_nums.size(): " << prime_nums.size() << endl;

			for (auto &num : prime_nums)
			{
				// if (num != "121313")
				// 	continue;
				cout << "check: " << num << endl;
				// check if meet d1-d2-d3-i1-d5-i2-d7-...-dn format
				for (int i1 = 0; i1 < digits; ++i1)
				{
					for (int i2 = i1 + 1; i2 < digits; ++i2)
					{
						if (num[i1] != num[i2])
							continue;
						vector<string> prime_value_family;
						prime_value_family.push_back(num);
						for (auto &next : prime_nums)
						{
							bool bOk = true;
							if (num >= next)
								continue;
							if (next[i1] != next[i2])
							{
								bOk = false;
								continue;
							}
							for (int n = 0; n < digits; ++n)
							{
								if (n == i1 || n == i2)
								{
									if (num[n] == next[n])
									{
										bOk = false;
										break;
									}
								}
								else
								{
									if (num[n] != next[n])
									{
										bOk = false;
										break;
									}
								}
							}
							if (!bOk)
								continue;

							prime_value_family.push_back(next);
							if (prime_value_family.size() == 8)
							{
								cout << "i1:" << i1 << " i2:" << i2 << endl;
								for (auto &p : prime_value_family)
									cout << p << " ";
								cout << endl;
								return true;
							}
						}
					}
				}
			}
		}
		return true;
	}
	catch (...)
	{
		cout << "Exception" << endl;
		return false;
	}
}
