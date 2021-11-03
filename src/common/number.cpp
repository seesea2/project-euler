#include "number.h"

bool IsEven(const uint64_t kNum)
{
	if (kNum == 0)
		return false;

	if (kNum / 2 == double(kNum) / 2)
		return true;
	else
		return false;
}
