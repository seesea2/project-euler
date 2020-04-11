// Consecutive prime sum
/*
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime,
 contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

	Answer:
	997651

*/

#include "1_99.h"

bool P50()
{
	try
	{
		uint64_t num = 0, sum = 0;
		int consecutive = 0;
		const uint64_t kBoundary = 1000000;
		// const uint64_t kBoundary = 1000;

		vector<uint64_t> prime_list;

		uint64_t latest_prime = 0;
		num = 1;
		cout << "preparing list of prime numbers" << endl;
		while (1)
		{
			if (IsPrime(num))
			{
				if (latest_prime + num > kBoundary)
					break;
				prime_list.push_back(num);
				latest_prime = num;
			}
			num += 1;
			if (num >= kBoundary)
				break;
		}
		cout << "prime_list: " << prime_list.size() << endl;

		sum = 0;
		consecutive = prime_list.size();
		while (1)
		{
			cout << "consecutive : " << consecutive << endl;
			for (auto it = prime_list.begin(); it != prime_list.end(); ++it)
			{
				if (it - prime_list.begin() + size_t(consecutive) > prime_list.size())
					break;

				sum = 0;
				for (int i = 0; i < consecutive; ++i)
					sum += *(it + i);

				if (sum >= kBoundary)
					break;
				if (IsPrime(sum))
				{
					cout << "Longest consecutive : " << consecutive << endl;	   //543
					cout << "Prime of longest consecutive prime: " << sum << endl; //997651
					return true;
				}
			}

			--consecutive;
			if (consecutive <= 0)
				break;
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}
