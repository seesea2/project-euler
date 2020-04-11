#include "number.h"

bool IsPrime(const uint64_t kNum)
{
	if (kNum < 2)
		return false;

	vector<uint64_t> factors = GetFactors(kNum);
	if (factors.empty())
		return true;

	return false;
}
