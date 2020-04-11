// Power digit sum
/*
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2 power 1000?

	Answer:
	1366
*/

#include "number.h"

void p16()
{
	BigNumber num(1);

	int i;
	const int POWER = 1000;

	for (i = 0; i < POWER; ++i)
		num *= 2;

	uint64_t sum = 0;
	for (auto i = num.number_.begin(); i != num.number_.end(); ++i)
		sum += *i;

	cout << "DigitsSum for 2 power of 1000 is: " << sum << endl;
}
