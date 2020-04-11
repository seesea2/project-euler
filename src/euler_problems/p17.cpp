// Number letter counts
/*
	If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
	then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

	If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, 
	how many letters would be used?

	NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters 
	and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is 
	in compliance with British usage.

	Answer:
	21124
*/

#include "1_99.h"

int num_letter_counts(const int num);
int count_1_to_19(const int num);
int count_20_to_99(const int num);
int count_100_to_999(const int num);
int count_1000_to_9999(const int num);

bool P17()
{
	try
	{
		const int NUM_RANGE = 1000;
		int count = 0, num;

		num = NUM_RANGE;
		while (num > 0)
		{
			count += num_letter_counts(num);
			--num;
		}

		cout << "Letter Counts : " << count << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

int num_letter_counts(const int num)
{
	if (num <= 19)
		return count_1_to_19(num);
	else if (num <= 99)
		return count_20_to_99(num);
	else if (num <= 999)
		return count_100_to_999(num);
	else if (num <= 9999)
		return count_1000_to_9999(num);

	return 0;
}

int count_1_to_19(const int num)
{
	if (num < 1 || num > 19)
		return 0;

	const string words[] = {
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
		"sixteen", "seventeen", "eighteen", "nineteen"};

	return words[num - 1].length();
}

int count_20_to_99(const int num)
{
	if (num < 20 || num > 99)
		return 0;

	const string words[] = {
		"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	int count = 0;
	int temp;
	temp = num - num / 10 * 10;
	count += words[num / 10 - 2].length();
	count += count_1_to_19(temp);

	return count;
}

int count_100_to_999(const int num)
{
	if (num < 100 || num > 999)
		return 0;

	const string words = "hundred", and_str = "and";

	int count = 0;
	int temp;

	count += count_1_to_19(num / 100);
	count += words.length();

	temp = num - num / 100 * 100;
	if (temp >= 20)
	{
		count += and_str.length();
		count += count_20_to_99(temp);
	}
	else if (temp > 0)
	{
		count += and_str.length();
		count += count_1_to_19(temp);
	}

	return count;
}

int count_1000_to_9999(const int num)
{
	if (num < 1000 || num > 9999)
		return 0;

	const string words = "thousand";

	int count = 0;
	int temp;

	temp = num - num / 1000 * 1000;
	count += count_1_to_19(num / 1000);
	count += words.length();

	if (temp > 0)
	{
		count += count_100_to_999(temp);
	}

	return count;
}