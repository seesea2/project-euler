//Largest prime factor
/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include "../header.h"
#include "../math_functions.h"


void Problem3()
{
	double num = 600851475143 , boundary;
	double temp;
	
	boundary = floor(num / 2);

	do
	{
		temp = GetMaxFactorWithBoundary(num, boundary);
		if(IsPrime(temp))
		{
			cout << "Largest prime factor of 600851475143 is : " << temp << endl;
			break;
		}
		else
		{
			boundary = temp - 1;
		}

		if(boundary < 1)
		{
			cout << "No finding" << endl;
			break;
		}
	}while(1);
}
