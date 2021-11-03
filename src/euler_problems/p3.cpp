// Largest prime factor
/*
	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?

	Answer:
	6857
*/

#include "1_99.h"

bool P3()
{
	try
	{

		uint64_t num = 600851475143;

		auto factors = GetFactors(num);
		for (auto ind = factors.rbegin(); ind != factors.rend(); ++ind)
		{
			if (IsPrime(*ind))
			{
				cout << "Largest prime factor of 600851475143 is : " << *ind << endl;
				return true;
			}
		}

		cout << "No Prime Factor found." << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
