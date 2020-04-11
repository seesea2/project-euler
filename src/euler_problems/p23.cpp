// Non-abundant sums
/*
	A perfect number is a number for which the sum of its proper divisors 
	is exactly equal to the number. 
	For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, 
	which means that 28 is a perfect number.

	A number n is called deficient if the sum of its proper divisors 
	is less than n and it is called abundant if this sum exceeds n.

	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, 
	the smallest number that can be written as the sum of two abundant numbers is 24. 
	By mathematical analysis, it can be shown that all integers 
	greater than 28123 can be written as the sum of two abundant numbers. 
	However, this upper limit cannot be reduced any further by analysis 
	even though it is known that the greatest number 
	that cannot be expressed as the sum of two abundant numbers is less than this limit.

	Find the sum of all the positive integers 
	which cannot be written as the sum of two abundant numbers.

	Answer:
	4179871
*/

#include "1_99.h"

bool P23()
{
	try
	{
		const int kKnowUpperLimit = 28123;
		int new_upper_limit = 0; //rslt is: 20162
		uint64_t sum = 0;		 //rslt is: 4179871

		vector<int> abundant_nums;
		for (int i = 1; i < kKnowUpperLimit; ++i)
		{
			if (IsAbundantNum(i) == true)
				abundant_nums.push_back(i);
		}
		cout << "abundant_num_list.size : " << abundant_nums.size() << endl;

		//find new upper limit that can be sum of two abundant numbers.
		bool search_new_upper_limit = true;
		bool sum_of_two_abundant = false;
		int num = kKnowUpperLimit - 1;
		while (num > 0)
		{
			sum_of_two_abundant = false;
			for (auto it1 = abundant_nums.begin(); it1 != abundant_nums.end(); ++it1)
			{
				if (*it1 >= num)
					break;

				//use binary search to speed up the search
				size_t lower_ind = 0, upper_ind = abundant_nums.size() - 1, ind = 0;
				if (*it1 + abundant_nums[lower_ind] == num || *it1 + abundant_nums[upper_ind] == num)
				{
					sum_of_two_abundant = true;
				}
				else
				{
					while (1)
					{
						ind = (lower_ind + upper_ind) / 2;
						if (*it1 + abundant_nums[ind] == num)
						{
							sum_of_two_abundant = true;
							break;
						}
						else if (*it1 + abundant_nums[ind] > num)
						{
							upper_ind = ind;
						}
						else //(*it1 + abundant_num_list[ind] < num)
						{
							lower_ind = ind;
						}

						if (lower_ind + 1 >= upper_ind)
							break;
					}
				}

				if (sum_of_two_abundant == true)
					break;
			}

			if (search_new_upper_limit && sum_of_two_abundant == true)
			{
				new_upper_limit = num;
			}
			// once not sum of two abundant, stop upper search.
			else if (sum_of_two_abundant == false)
			{
				search_new_upper_limit = false;
				cout << "non_two_abundant_nums :  " << num << endl;
				sum += num;
			}

			--num;
		}
		cout << endl;
		cout << "new_upper_limit : " << new_upper_limit << endl;
		cout << "Sum of all non_two_abundant_numbers : " << sum << endl
			 << endl;
			 
		return true;
	}
	catch (...)
	{
		return false;
	}
}
