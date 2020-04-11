// Permuted multiples
/*
It can be seen that the number, 125874, and its double, 251748, 
contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, 
and 6x, contain the same digits.

	Answer:
	142857

*/

#include "1_99.h"

bool P52()
{
	try
	{
		bool found = true;
		uint64_t num = 0, temp;
		string numStr, tempStr;

		do
		{
			++num;
			numStr = to_string(num);
			sort(numStr.begin(), numStr.end());

			found = true;
			for (auto i = 2; i <= 6; ++i)
			{
				temp = num;
				temp *= i;
				tempStr = to_string(temp);
				sort(tempStr.begin(), tempStr.end());
				if (numStr != tempStr)
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				cout << "Answer: " << num << endl;
				break;
			}
		} while (1);
		return true;
	}
	catch (...)
	{
		return false;
	}
}