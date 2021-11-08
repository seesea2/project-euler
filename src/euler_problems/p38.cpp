// Pandigital multiples
/*
Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. 
We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, 
giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed 
as the concatenated product of an integer with (1,2, ... , n) where n > 1?

	Answer:	932718654
*/

#include "1_99.h"

bool P38()
{
	try
	{
		string max_num_string = "";
		// num maximum lengh is half length of "123456789"
		for (uint64_t num = 1; num < 98765; ++num)
		{
			string concatenated_num = to_string(num);
			for (int n = 2; n < 9; ++n)
			{
				if (concatenated_num.size() < 9)
					concatenated_num += to_string(num * n);
				if (concatenated_num.size() >= 9)
					break;
			}
			if (concatenated_num.size() != 9)
				continue;

			string num_str = concatenated_num;
			sort(num_str.begin(), num_str.end());
			if (num_str != "123456789")
				continue;

			cout << concatenated_num << endl;
			if (concatenated_num > max_num_string)
				max_num_string = concatenated_num;
		}

		cout << "Answer: " << max_num_string << endl;
		return true;
	}
	catch (std::exception &ex)
	{
		cout << "std Excption:" << ex.what() << endl;
		return false;
	}
	catch (...)
	{
		cout << "Exception" << endl;
		return false;
	}
}
