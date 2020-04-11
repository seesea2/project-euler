// Permuted multiples
/*
It can be seen that the number, 125874, and its double, 251748, 
contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, 
and 6x, contain the same digits.

	Answer:
	142857

*/

#include "51_100.h"

void p52()
{
	uint64_t num = 0, temp;
	string numStr, tempStr;

	do
	{
		++num;

		temp = num;
		temp *= 2;

		numStr = to_string(num);
		sort(numStr.begin(), numStr.end());
		tempStr = to_string(temp);
		sort(tempStr.begin(), tempStr.end());
		if (numStr != tempStr)
			continue;

		temp = num;
		temp *= 3;
		tempStr = to_string(temp);
		sort(tempStr.begin(), tempStr.end());
		if (numStr != tempStr)
			continue;

		temp = num;
		temp *= 4;
		tempStr = to_string(temp);
		sort(tempStr.begin(), tempStr.end());
		if (numStr != tempStr)
			continue;

		temp = num;
		temp *= 5;
		tempStr = to_string(temp);
		sort(tempStr.begin(), tempStr.end());
		if (numStr != tempStr)
			continue;

		temp = num;
		temp *= 6;
		tempStr = to_string(temp);
		sort(tempStr.begin(), tempStr.end());
		if (numStr != tempStr)
			continue;

		cout << num << endl;
		break;
	} while (1);
}