//Consecutive prime sum
/*
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

#include "../header.h"
#include "../math_functions.h"

void Problem50() {
	double num = 0.0, sum = 0.0, longest_sum = 0;
	int longest_consecutive = 0, consecutive = 0;
	const double kBoundary = 1000000;
	//const double kBoundary = 1000;

	vector<double> prime_list;

	num = 1;
	while(1)
	{
		if(IsPrime(num))
		{
			prime_list.push_back(num);
		}

		num += 1;
		if(num >= kBoundary)
			break;
	}
	cout << prime_list.size() << endl << endl;

	sum = 0;
	consecutive = 2;
	while(1)
	{
		cout << "consecutive : " << consecutive << endl;
		for(vector<double>::iterator it = prime_list.begin(); it != prime_list.end(); ++it) 
		{
			if(it - prime_list.begin() + size_t(consecutive) > prime_list.size())
				break;

			sum = 0;
			for(int i = 0; i < consecutive; ++i)
			{
				sum += *(it + i);
			}

 			if(sum >= kBoundary)
				break;
			if(IsPrime(sum))
			//if(find(prime_list.begin(), prime_list.end(), sum) != prime_list.end())
			{
				longest_consecutive = consecutive;
				longest_sum = sum;
				break;
			}
		}

		++consecutive;
		if(consecutive >= kBoundary)
			break;
	}

	cout << endl;
	cout << "longest_consecutive : " << longest_consecutive << endl;	//543
	cout << "longest_sum  : " << longest_sum << endl << endl;			//997651
}


