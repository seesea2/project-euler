//Reciprocal cycles
/*
A unit fraction contains 1 in the numerator. The decimal representation 
of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1 

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. 
It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

*/

#include "../header.h"
#include "../debug_header.h"

void Problem26() {
	DebugFunctionBegin("Problem26()");
	
	const int kBoundary = 1000;
	int d = 1, longest_recurring_d = 1;		//final rslt is 983
	int longest_recurring_cycle = 0;		//final rslt is 982
	string fraction_part;
	vector<int> remainder_list;


	int val = 1, quotient = 0, remainder = 0;
	for(d = 1, val = 1; d < kBoundary; ++d)
	//for(d = 1; d < 10; ++d)
	{
		if(d == 1)
			cout << "d : " << endl;
		cout << setw(4) << d;
		DebugPrint("d is " + to_string(d));

		bool got_recurring_cycle = false;

		val = 1;
		fraction_part.clear();
		remainder_list.clear();
		remainder_list.push_back(val);
		val *= 10;
		while(val)
		{
			DebugPrint("val is " + to_string(val));
			if(val < d)
			{
				val *= 10;
				fraction_part += to_string(0);
				continue;
			}

			quotient = val / d;
			remainder = val - quotient * d;
			if(remainder == 0) // can be devided & no reoccuring cycle.
				break;

			for(size_t i = 0; i < remainder_list.size(); ++i)
			{
				DebugPrint("i is " + to_string(i));
				if(remainder == remainder_list[i])
				{
					fraction_part += to_string(quotient);

					if(size_t(longest_recurring_cycle) < fraction_part.length() - i)
					{
						longest_recurring_d = d;
						longest_recurring_cycle = fraction_part.length() - i;

						DebugPrint("longest_recurring_cycle : " + to_string(longest_recurring_cycle));
					}
					got_recurring_cycle = true;
					break;
				}
			}

			if(got_recurring_cycle == true)
				break;

			fraction_part += to_string(quotient);
			remainder_list.push_back(remainder);
			val = remainder * 10;
		}
	}

	cout << endl;
	cout << "longest_recurring_d : " << longest_recurring_d << endl;
	cout << "longest_recurring_cycle : " << longest_recurring_cycle << endl << endl;
}

