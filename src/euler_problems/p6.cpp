// Sum square difference
/*
	The sum of the squares of the first ten natural numbers is,
	1^2 + 2^2 + ... + 10^2 = 385

	The square of the sum of the first ten natural numbers is,
	(1 + 2 + ... + 10)^2 = 55^2 = 3025

	Hence the difference between the sum of the squares of the first ten natural numbers 
	and the square of the sum is 3025 - 385 = 2640.

	Find the difference between the sum of the squares of the 
	first one hundred natural numbers and the square of the sum.

	Answer:
	25164150
*/

#include "1_99.h"

bool P6()
{
	try
	{
		uint64_t sumOfSquare = 0, squareOfSum = 0;

		for (int i = 1; i <= 100; ++i)
		{
			sumOfSquare += i * i;
			squareOfSum += i;
		}
		squareOfSum *= squareOfSum;

		cout << "Difference is : "
			 << (sumOfSquare > squareOfSum ? sumOfSquare - squareOfSum : squareOfSum - sumOfSquare)
			 << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}