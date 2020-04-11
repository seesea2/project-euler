// Bouncy numbers
/*
Working from left-to-right if no digit is exceeded by the digit to its left 
it is called an increasing number; for example, 134468.

Similarly if no digit is exceeded by the digit to its right it is called a 
decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing nor decreasing 
a "bouncy" number; for example, 155349.

Clearly there cannot be any bouncy numbers below one-hundred, 
but just over half of the numbers below one-thousand (525) are bouncy. 
In fact, the least number for which the proportion of bouncy numbers 
first reaches 50% is 538.

Surprisingly, bouncy numbers become more and more common and by the time 
we reach 21780 the proportion of bouncy numbers is equal to 90%.

Find the least number for which the proportion of bouncy numbers is exactly 99%.


	Answer:
	1587000

*/

#include "101_150.h"

void p112()
{
	int i = 0;
	uint64_t decreasing_num_qty = 0, increasing_num_qty = 0, bouncy_num_qty = 0;

	while (++i)
	{
		cout << i << endl;
		if (IsDecreasingNumber(i))
			decreasing_num_qty += 1;
		else if (IsIncreasingNumber(i))
			increasing_num_qty += 1;
		else
			bouncy_num_qty += 1;

		if (bouncy_num_qty * 1.0 / i >= 0.99)
			break;
	}

	cout << decreasing_num_qty << " : " << increasing_num_qty << " : " << bouncy_num_qty << endl;
	cout << "Bouncy numbers reach 99% at : " << i << endl;
}
