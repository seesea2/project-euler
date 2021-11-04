// Double-base palindromes
/*

The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, 
which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

	Answer:	872187
*/

#include "1_99.h"

bool Palindrome(const string str)
{
	for (size_t front = 0, back = str.size() - 1; front < back; ++front, --back)
	{
		if (str[front] != str[back])
			return false;
	}
	return true;
}

bool P36()
{
	try
	{
		const int kMax = 1000000;
		uint64_t sum = 0;

		for (auto num = 1; num < kMax; ++num)
		{
			string num_str = to_string(num);
			if (!Palindrome(num_str))
				continue;

			if (!NumToBinary(num, num_str))
			{
				cout << "Exception" << endl;
				continue;
			}
			if (!Palindrome(num_str))
				continue;

			cout << "parlindrome num: " << num << endl;
			sum += num;
		}
		cout << "Answer: " << sum << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
