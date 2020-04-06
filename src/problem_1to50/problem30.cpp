//Digit fifth powers
/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1 power 4 + 6 power 4 + 3 power 4 + 4 power 4
    8208 = 8 power 4 + 2 power 4 + 0 power 4 + 8 power 4
    9474 = 9 power 4 + 4 power 4 + 7 power 4 + 4 power 4

As 1 = 1 power 4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

*/
#include "../header.h"


void Problem30()
{
	double sum = 0;

	long num, remaining, digit_power, powers_sum;
	int digit;
	
	num = 2; //start from 2 instead of 1
	while(1)
	{
		remaining = num;
		powers_sum = 0;
		while(remaining > 0)
		{
			digit = remaining - remaining / 10 * 10;
			digit_power = 1;
			for(int j = 0; j < 5; ++j)
				digit_power *= digit;

			powers_sum += digit_power;
			remaining /= 10;
		}

		if(powers_sum == num)
		{
			sum += num;
			cout << "number : " << num << endl;
		}

		++num;
		if(num > 1000000) //the Range is basing on calculation/estimation.
			break;
	}
	cout << "Sum of all the numbers is : " << sum << endl;
}
