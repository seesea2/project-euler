//Power digit sum
/*
2 power 15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2 power 1000?
*/

#include "../header.h"
#include "../big_number_class.h"

void Problem16()
{
	BigNumberC num("1");

	int i;
	const int POWER = 1000;

	for(i = 0; i < POWER; ++i)
	{
		num.Multiply(2);
	}

	cout << "DigitsSum for 2 power of 1000 -- ";
	cout << num.GetDigitsSum() << endl;
}
