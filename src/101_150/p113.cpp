// Non-bouncy numbers
/*
Working from left-to-right if no digit is exceeded by the digit to its left
 it is called an increasing number; for example, 134468.
Similarly if no digit is exceeded by the digit to its right it is called a
 decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing
 nor decreasing a "bouncy" number; for example, 155349.

As n increases, the proportion of bouncy numbers below n increases
 such that there are only 12951 numbers below one-million that are not bouncy
 and only 277032 non-bouncy numbers below 10 power 10.

How many numbers below a googol (10 power 100) are not bouncy?

	Answer:
	51161058134250
*/

#include "101_150.h"
#include "debug.h"

/* solution note:
d_qi(m) mean qty of decreasing number with m digits and ends with i.

there are equations: 

d_q0(n + 1) = d_q9(n) + ... + d_q1(n) + d_q0(n);
d_q1(n + 1) = d_q9(n) + ... + d_q1(n);
d_q2(n + 1) = d_q9(n) + ... + d_q2(n);
...
d_q9(n + 1) = d_q9(n);

Similarly, increasing number
i_q1(n + 1) = i_q1(n);
i_q2(n + 1) = i_q1(n) + i_q2(n);
...
i_q9(n + 1) = i_q1(n) + i_q2(n) + ... + i_q9(n);
*/

void p113()
{
	BigNumber decrease_num_qty_n[10], decrease_num_qty_n_1[10];
	BigNumber increase_num_qty_n[10], increase_num_qty_n_1[10];
	BigNumber total_qty(0);

	decrease_num_qty_n[0] = 0;
	for (size_t i = 1; i < 10; ++i)
	{
		decrease_num_qty_n[i] = BigNumber(1);
		increase_num_qty_n[i] = BigNumber(1);
	}
	//all single digit numbers are decreasing & increasing numbers
	total_qty += BigNumber(9);

	int num_digits_cnt = 1;
	//each loop is for numbers with num_digits_cnt digitis
	while (1)
	{
		++num_digits_cnt;

		for (size_t i = 0; i < 10; ++i)
		{
			decrease_num_qty_n_1[i] = BigNumber(0);
			for (size_t j = i; j < 10; ++j)
				decrease_num_qty_n_1[i] += decrease_num_qty_n[j];
		}
		for (size_t i = 0; i < 10; ++i)
		{
			decrease_num_qty_n[i] = decrease_num_qty_n_1[i];
			total_qty += decrease_num_qty_n[i];
		}

		for (size_t i = 1; i < 10; ++i)
		{
			increase_num_qty_n_1[i] = BigNumber(0);
			for (size_t j = 1; j <= i; ++j)
				increase_num_qty_n_1[i] += increase_num_qty_n[j];
		}
		for (size_t i = 1; i < 10; ++i)
		{
			increase_num_qty_n[i] = increase_num_qty_n_1[i];
			total_qty += increase_num_qty_n[i];
		}

		// handle duplicate in both decrease_num_qty_n, increase_num_qty_n,
		// e.g. 11, 22, 33 ...
		total_qty -= BigNumber(9);

		cout << "num_digits_cnt  : " << num_digits_cnt << "  total_qty : " << total_qty << endl;
		if (num_digits_cnt >= 100)
			break;
	}

	cout << endl
			 << "Non-bouncy numbers below 10 power 100 Qyt is : " << total_qty << endl
			 << endl;
}
