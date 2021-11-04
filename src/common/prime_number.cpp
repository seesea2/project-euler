#include "number.h"

bool IsPrime(const uint64_t kNum)
{
	if (kNum <= 0)
		return false;

	string num_str = to_string(kNum);
	if (num_str.length() > 1 &&
		(num_str.back() == '2' || num_str.back() == '4' || num_str.back() == '5' ||
		 num_str.back() == '6' || num_str.back() == '8' || num_str.back() == '0'))
		return false;

	if (GetFactors(kNum).empty())
		return true;

	return false;
}
