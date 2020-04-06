//Non-bouncy numbers
/*
Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; 
for example, 134468.
Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.

As n increases, the proportion of bouncy numbers below n increases such that there are only 12951 numbers 
below one-million that are not bouncy and only 277032 non-bouncy numbers below 10 power 10.

How many numbers below a googol (10 power 100) are not bouncy?
*/


#include "../header.h"
#include "../big_number_class.h"
#include "../debug_header.h"

/*
d_qi(m) mean  qty of decreasing number with m digits and ends with 0.

there are equations: 

d_q0(n + 1) = d_q9(n) + ... + d_q1(n) + d_q0(n);
d_q1(n + 1) = d_q9(n) + ... + d_q1(n);
d_q2(n + 1) = d_q9(n) + ... + d_q2(n);
...
d_q9(n + 1) = d_q9(n);

i_q1(n + 1) = i_q1(n);
i_q2(n + 1) = i_q1(n) + i_q2(n);
...
i_q9(n + 1) = i_q1(n) + i_q2(n) + ... + i_q9(n);
*/

void Problem113() {
	BigNumberC decrease_num_qty_n[10], decrease_num_qty_n_1[10];
	BigNumberC increase_num_qty_n[10], increase_num_qty_n_1[10];
	BigNumberC total_qty(0);

	decrease_num_qty_n[0] = 0;
	for(size_t i = 1; i < 10; ++i)
	{
		decrease_num_qty_n[i] = BigNumberC(1);
		increase_num_qty_n[i] = BigNumberC(1);
	}
	//all single digit numbers are decreasing & increasing numbers
	total_qty += BigNumberC(9);

	int num_digits_cnt = 1;
	//each loop is for numbers with num_digits_cnt digitis
	while(1)
	{
		++num_digits_cnt;

		for(size_t i = 0; i < 10; ++i)
		{
			for(size_t j = i; j < 10; ++j)
				decrease_num_qty_n_1[i] += decrease_num_qty_n[j];
		}
		for(size_t i = 0; i < 10; ++i)
		{
			decrease_num_qty_n[i] = decrease_num_qty_n_1[i];
			decrease_num_qty_n_1[i] = BigNumberC(0);
			total_qty += decrease_num_qty_n[i];
		}

		for(size_t i = 0; i < 10; ++i)
		{
			for(size_t j = 1; j <= i; ++j)
				increase_num_qty_n_1[i] += increase_num_qty_n[j];
		}
		for(size_t i = 0; i < 10; ++i)
		{
			increase_num_qty_n[i] = increase_num_qty_n_1[i];
			increase_num_qty_n_1[i] = BigNumberC(0);
			total_qty += increase_num_qty_n[i];
		}

		//consider duplicate e.g. 11, 22, 33 ... in decrease_num_qty_n & increase_num_qty_n
		total_qty -= BigNumberC(9);

		cout << "num_digits_cnt  : " << num_digits_cnt << "  total_qty : " << total_qty << endl;
		if(num_digits_cnt >= 100)
			break;
	}

 	cout << endl << "Non-bouncy numbers below 10 power 100 Qyt is : " << total_qty << endl << endl;

}


//Solution1() has memory failure Exception when n > 16. Cannot work.
void Solution1() {
	DebugFunctionBegin("Problem113()");

	size_t qty = 0;

	vector<string> decrease_numbers_list, decrease_numbers_list_temp, increase_numbers_list, increase_numbers_list_temp;
	//all single digit numbers are decreasing & increasing numbers
	for(int i = 1; i <= 9; ++i)
	{
		decrease_numbers_list.push_back(to_string(i));
		increase_numbers_list.push_back(to_string(i));
	}
	qty += 9;
	DebugPrint("test 1 qty = " + to_string(qty)); 

	string str, str_for_char;
	for(int n = 2; n < 100; ++n) //for each numbers with n digitis
	//for(int n = 2; n <= 10; ++n)
	{
		DebugPrint("number digits qty : " + to_string(n));
		for(vector<string>::iterator it = decrease_numbers_list.begin(); it != decrease_numbers_list.end(); ++it)
		{
			str = *it;
			str_for_char = str.back();
			DebugPrint("c is : " + str_for_char);
			for(int i = 0; i <= stoi(str_for_char); ++i)
				decrease_numbers_list_temp.push_back(str + to_string(i));
		}
		decrease_numbers_list.clear();
		decrease_numbers_list = decrease_numbers_list_temp;
		decrease_numbers_list_temp.clear();
		size_t q1 = decrease_numbers_list.size();
		DebugPrint("decrease_numbers_list.size() = " + to_string(q1));
		qty += q1;

		for(vector<string>::iterator it = increase_numbers_list.begin(); it != increase_numbers_list.end(); ++it)
		{
			str = *it;
			str_for_char = str.back();
			for(int i = 9; i >= stoi(str_for_char); --i)
				increase_numbers_list_temp.push_back(str + to_string(i));
		}
		increase_numbers_list.clear();
		increase_numbers_list = increase_numbers_list_temp;
		increase_numbers_list_temp.clear();
		size_t q2 = increase_numbers_list.size();
		DebugPrint("increase_numbers_list.size() = " + to_string(q2));
		qty += q2;

		qty -= 9; //consider duplicate 11, 22, 33 ... in decrease_numbers_list & increase_numbers_list
		cout << "Non-bouncy numbers below 10 power " << n << ", the qty is : " << qty << endl;
	}

	cout << endl << "Non-bouncy numbers : " << qty << endl << endl;
}


