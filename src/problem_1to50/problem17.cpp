//Number letter counts
/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, 
how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters 
and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is 
in compliance with British usage.
*/

#include "../header.h"

int count_1_to_19(const int num);
int count_20_to_99(const int num);
int count_100_to_999(const int num);
int count_1000_to_9999(const int num);


void Problem17()
{
	const int NUM_RANGE = 1000;
	int count = 0, num;

	num = NUM_RANGE;
	while(num > 0)
	{
		if(num <= 19)
		{
			count += count_1_to_19(num);
		}
		else if(num <= 99)
		{
			count += count_20_to_99(num);
		}
		else if(num <= 999)
		{
			count += count_100_to_999(num);
		}
		else if(num <= 9999)
		{
			count += count_1000_to_9999(num);
		}
		--num;
	}

	cout << "Letter Counts : " << count << endl;

	return;
}
int count_1_to_19(const int num)
{
	if(num < 1)
		return 0;

	char *words[] = 
	{
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
		"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};

	return strlen(words[num - 1]);
}
int count_20_to_99(const int num)
{
	if(num < 1)
		return 0;

	char *words[] = 
	{
		"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
	};

	int count = 0;
	int temp;
	temp = num - num / 10 * 10;
	count += strlen(words[num / 10 - 2]);
	count += count_1_to_19(temp);
	
	return count;
}
int count_100_to_999(const int num)
{
	if(num < 1)
		return 0;

	char words[] = "hundred", and[] = "and";

	int count = 0;
	int temp;

	count += count_1_to_19(num / 100);
	count += strlen(words);

	temp = num - num / 100 * 100;
	if(temp >= 20)
	{
		count += strlen(and);
		count += count_20_to_99(temp);
	}
	else if(temp > 0)
	{
		count += strlen(and);
		count += count_1_to_19(temp);
	}

	return count;
}
int count_1000_to_9999(const int num)
{
	if(num < 1)
		return 0;

	char words[] = "thousand";

	int count = 0;
	int temp;

	temp = num - num / 1000 * 1000;
	count += count_1_to_19(num / 1000);
	count += strlen(words);

	if(temp > 0)
	{
		count += count_100_to_999(temp);
	}
	
	return count;
}