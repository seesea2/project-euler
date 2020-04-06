#include "math_functions.h"


double GetMaxFactorWithBoundary(const double kNum, const double kBoundary)
{
	if(kBoundary <= 0)
		return 0;
	if(kNum / kBoundary == floor(kNum / kBoundary))
		return kBoundary;

	double a, b;
	double temp1, temp2;
	double ret = 1;

	a = max(2.0, ceil(kNum/kBoundary)), b = min(kBoundary, floor(kNum/2));
	do
	{
		temp1 = kNum / a;
		if(temp1 == floor(temp1))
		{
			if(temp1 < kBoundary)
				ret = temp1;
			b = temp1 - 1;
		}

		temp2 = kNum / b;
		if(temp2 == ceil(temp2))
		{
			if(temp2 < kBoundary)
				ret = max(ret, b);
			a = temp2 + 1;
		}

		if(ret > 1)
			break;

		a = ceil(temp2);
		b = floor(temp1);

		if(b <= 1)
		{
			ret = 1;
			break;
		}
	}while(1);

	return ret;
}

bool IsPrime(const double kNum)
{
	bool ret = false;
	if(kNum < 2)
		;
	else if(kNum == 2)
		ret = true;
	else
	{
		double a = GetMaxFactorWithBoundary(kNum, kNum-1);
		
		if(a == 1)
			ret = true;
		else
			ret = false;
	}
	return ret;
}


bool IsEvenNum(const double kNum) {

	if(kNum / 2 == floor(kNum / 2))
		return true;
	else
		return false;
}


bool IsLeapYear(const int kYear)
{
	bool ret = false;

	if(kYear % 400 == 0)
		ret = true;
	else if(kYear % 100 == 0)
		ret = false;
	else if(kYear % 4 == 0)
		ret = true;
	else
		ret = false;

	return ret;
}

int GetAmicableNumber(const int kNum)
{
	int temp1, temp2, divisor;
	double range;

	range = kNum - 1;
	temp1 = 0;
	do
	{
		divisor = (int)GetMaxFactorWithBoundary((double)kNum, range);
		temp1 += divisor;

		range = divisor - 1;
	}while(range > 0);

	range = temp1 - 1;
	temp2 = 0;
	do
	{
		divisor = (int)GetMaxFactorWithBoundary((double)temp1, range);
		temp2 += divisor;

		range = divisor - 1;
	}while(range > 0);

	if(temp2 == kNum && temp1 != kNum)
		return temp1;
	else
		return 0;
}

//Totient maximum
bool IsRelativelyPrime(const double kA, const double kB)
{
	bool ret = true;

	double bound, temp;

	bound = kB;
	while(bound > 0)
	{
		temp = GetMaxFactorWithBoundary(kB, bound);
		if(temp <= 1)
			break;

		if(kA / temp == floor(kA / temp))
		{
			ret = false;
			break;
		}
		bound = temp - 1;
	}

	return ret;
}

bool IsAbundantNum(const double kNum) {
	double factor = kNum, sum = 0.0;

	while(1)
	{
		factor = GetMaxFactorWithBoundary(kNum, factor-1);

		if(factor > 0)
		{
			sum += factor;
		}
		else
			break;
	}

	bool rslt = false;
	if(sum > kNum)
		rslt = true;
	else
		rslt = false;
	return rslt;
}

bool IsPerfectNum(const double kNum) {
	double factor = kNum, sum = 0.0;

	while(1)
	{
		factor = GetMaxFactorWithBoundary(kNum, factor-1);

		if(factor > 0)
		{
			sum += factor;
		}
		else
			break;
	}

	bool rslt = false;
	if(sum == kNum)
		rslt = true;
	else
		rslt = false;
	return rslt;
}

bool   IsDeficientNum(const double kNum) {
	double factor = kNum, sum = 0.0;

	while(1)
	{
		factor = GetMaxFactorWithBoundary(kNum, factor-1);

		if(factor > 0)
		{
			sum += factor;
		}
		else
			break;
	}

	bool rslt = false;
	if(sum < kNum)
		rslt = true;
	else
		rslt = false;
	return rslt;
}
