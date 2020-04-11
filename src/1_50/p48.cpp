// Self powers
/*
The series, 1 power 1 + 2 power 2 + 3 power 3 + ... + 10 power 10 = 10405071317.

Find the last ten digits of the series, 
	1 power 1 + 2 power 2 + 3 power 3 + ... + 1000 power 1000.


	Answer:
	9110846700
*/

#include "1_50.h"

void p48()
{
	const int NUM_RANGE = 1000;

	BigNumber sum;
	for (int i = 1; i <= NUM_RANGE; ++i)
	{
		cout << i << endl;
		BigNumber temp(1);
		for (int j = 1; j <= i; ++j)
			temp *= i;

		sum += temp;
	}

	cout << sum << endl;
}
