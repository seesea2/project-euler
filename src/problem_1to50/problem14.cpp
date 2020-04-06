//Longest Collatz sequence
/*
The following iterative sequence is defined for the set of positive integers:

n ¡ú n/2 (n is even)
n ¡ú 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 ¡ú 40 ¡ú 20 ¡ú 10 ¡ú 5 ¡ú 16 ¡ú 8 ¡ú 4 ¡ú 2 ¡ú 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/


#include "../header.h"

void Problem14()
{
	double val;
	int i;
	int best_start, best_cnt, temp_cnt;

	best_start = best_cnt = 0;
	for(i = 13; i < 1000000; ++i)
	{
		val = i;
		temp_cnt = 1;
		do
		{
			if(floor(val / 2) == val / 2)
				val /= 2;
			else
				val = 3 * val + 1;
			++temp_cnt;
		}while(val != 1);

		if(temp_cnt > best_cnt)
		{
			best_start = i;
			best_cnt = temp_cnt;
		}
	}

	cout << "Longest chain produced by : " << best_start << " - " << best_cnt << endl;
}