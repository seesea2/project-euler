// Truncatable primes
/*
The number 3797 has an interesting property. Being prime itself, 
it is possible to continuously remove digits from left to right, 
and remain prime at each stage: 3797, 797, 97, and 7. 
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable 
from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

	Answer:	748317
*/

#include "1_99.h"

bool P37()
{
	try
	{
		uint64_t num = 7;
		vector<uint64_t> primes;
		while (num++)
		{
			// cout << "check: " << num << endl;
			if (!IsPrime(num))
				continue;

			string num_str = to_string(num);
			// truncatable from left
			while (!num_str.empty())
			{
				num_str = num_str.substr(1);
				if (num_str.empty())
					continue;
				// cout << "num_str: " << num_str << endl;
				uint64_t temp_num = stoll(num_str);
				if (!IsPrime(temp_num))
					break;
			}
			if (!num_str.empty())
				continue;

			num_str = to_string(num);
			// truncatable from right
			while (!num_str.empty())
			{
				num_str = num_str.substr(0, num_str.size() - 1);
				if (num_str.empty())
					continue;
				// cout << "num_str2: " << num_str << endl;
				uint64_t temp_num = stoll(num_str);
				if (!IsPrime(temp_num))
					break;
			}
			if (!num_str.empty())
				continue;

			primes.push_back(num);
			if (primes.size() >= 11)
				break;
		}

		uint64_t sum = 0;
		cout << "primes.size(): " << primes.size() << endl;
		for (auto &p : primes)
		{
			cout << p << endl;
			sum += p;
		}

		cout << "Answer: " << sum << endl;
		return true;
	}
	catch (std::exception &ex)
	{
		cout << "std Excption:" << ex.what() << endl;
		return false;
	}
	catch (...)
	{
		cout << "Exception" << endl;
		return false;
	}
}
