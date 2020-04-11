// Longest Collatz sequence
/*
	The following iterative sequence is defined for the set of positive integers:

	n -> n/2 (n is even)
	n -> 3n + 1 (n is odd)

	Using the rule above and starting with 13, we generate the following sequence:
	13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
	Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

	Which starting number, under one million, produces the longest chain?
	NOTE: Once the chain starts the terms are allowed to go above one million.

	Answer:
	837799
*/

#include "number.h"

void p14()
{
	uint64_t val;
	int i;
	int best_start, best_cnt, temp_cnt;

	best_start = best_cnt = 0;
	for (i = 13; i < 1000000; ++i)
	{
		val = i;
		temp_cnt = 1;
		do
		{
			if (IsEven(val))
				val /= 2;
			else
				val = 3 * val + 1;
			++temp_cnt;
		} while (val != 1);

		if (temp_cnt > best_cnt)
		{
			best_start = i;
			best_cnt = temp_cnt;
		}
	}

	cout << "Longest chain produced by : " << best_start << " - " << best_cnt << endl;
}