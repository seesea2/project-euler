// Smallest multiple
/*
	2520 is the smallest number that can be divided by each of 
	the numbers from 1 to 10 without any remainder.

	What is the smallest positive number that is evenly divisible 
	by all of the numbers from 1 to 20?


	Answer:
	232792560
*/

#include "1_50.h"

void p5()
{
	uint64_t num_base = 1, num = 1, temp;
	int i, multiple;

	for (i = 1; i <= 20; ++i)
	{
		if (IsPrime(i))
			num_base *= i;
	}

	multiple = 1;
	do
	{
		num = num_base * multiple;

		for (i = 20; i > 1; --i)
		{
			temp = num / i;
			if (temp != double(num) / i)
				break;
		}
		
		if (i <= 1)
			break;
	} while (++multiple);

	cout << "smallest number evenly divisible by 1 to 20 is : " << num << endl;
}