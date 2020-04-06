//Self powers
/*
The series, 1 power 1 + 2 power 2 + 3 power 3 + ... + 10 power 10 = 10405071317.

Find the last ten digits of the series, 1 power 1 + 2 power 2 + 3 power 3 + ... + 1000 power 1000.
*/

#include "../header.h"
#include "../big_number_class.h"


void Problem48()
{
	const int NUM_RANGE = 1000;

	BigNumberC sum(0);
	for(int i = 1; i <= NUM_RANGE; ++i)
	{
		BigNumberC temp(1);
		for(int j = 1; j <= i; ++j)
			temp.Multiply(i);

		sum.Plus(temp);
	}

	//lych sum.Print();
	sum.PrintRearDigits(10);
}
