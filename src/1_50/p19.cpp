// Counting Sundays
/*
	You are given the following information, 
	but you may prefer to do some research for yourself.

			1 Jan 1900 was a Monday.
			Thirty days has September, April, June and November.
				All the rest have thirty-one,
				Saving February alone, Which has twenty-eight, rain or shine.
				And on leap years, twenty-nine.
			A leap year occurs on any year evenly divisible by 4,
				but not on a century unless it is divisible by 400.

	How many Sundays fell on the first of the month 
	during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

	Answer:
	171
*/

#include "1_50.h"

void p19()
{
	// const int weekdays[] = {1, 2, 3, 4, 5, 6, 7};
	const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int first_is_sunday = 0;
	long days_qty = 0;

	// days for year 1900.
	for (int i = 1; i <= 12; ++i)
		days_qty += month_days[i - 1];
	if (IsLeapYear(1900))
		++days_qty;

	// year 1901 ~ 2001
	for (int year = 1901; year <= 2000; ++year)
	{
		// month
		for (int i = 1; i <= 12; ++i)
		{
			// check first date of month i is Sunday.
			if ((days_qty + 1) % 7 == 0)
				++first_is_sunday;

			days_qty += month_days[i - 1];
			if (i == 2 && IsLeapYear(year))
				++days_qty;
		}
	}

	cout << "Qty of first_day_is_sunday : " << first_is_sunday << endl;
}