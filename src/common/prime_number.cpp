#include "number.h"

bool IsPrime(const uint64_t kNum)
{
	if (kNum <= 0)
		return false;

	if (GetFactors(kNum).empty())
		return true;

	return false;
}
