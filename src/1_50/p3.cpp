// Largest prime factor
/*
	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?

	Answer:
	6857
*/

#include "1_50.h"

void p3()
{
	uint64_t num = 600851475143;

	vector<uint64_t> factors = GetFactors(num);
	for (auto ind = factors.rbegin(); ind != factors.rend(); ++ind)
	{
		if (IsPrime(*ind))
		{
			cout << "Largest prime factor of 600851475143 is : " << *ind << endl;
			return;
		}
	}

	cout << "No Prime Factor found." << endl;
}
