// Factorial digit sum
/*
	n! means n x (n - 1) x ... x 3 x 2 x 1

	For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
	and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

	Find the sum of the digits in the number 100!


*/

#include "1_50.h"

void p20()
{
	BigNumber big_number(1);
	for (int i = 100; i > 0; --i)
		big_number *= i;

	uint64_t sum = 0;
	for (auto a = big_number.number_.begin(); a != big_number.number_.end(); ++a)
		sum += *a;

	cout << "100! is : " << big_number << endl;
	cout << "100! -- " << sum << endl;
}
