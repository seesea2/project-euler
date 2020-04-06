//Sum square difference
/*
The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers 
and the square of the sum is 3025 ? 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include "../header.h"



void Problem6()
{
	double sumOfSquare = 0, squareOfSum = 0;

	int i;

	for(i = 1; i <= 100; ++i)
	{
		sumOfSquare += i * i;
		
		squareOfSum += i;
	}

	squareOfSum *= squareOfSum;

	cout << "Difference is : " << abs(sumOfSquare - squareOfSum) << endl;

}