#include "../include/number.h"

bool IsEven(const uint64_t kNum)
{
	if (kNum == 0)
		return false;

	if (kNum / 2 == double(kNum) / 2)
		return true;
	else
		return false;
}

//Totient maximum
// bool IsRelativelyPrime(const double kA, const double kB)
// {
// 	bool ret = true;

// 	double bound, temp;

// 	bound = kB;
// 	while (bound > 0)
// 	{
// 		temp = GetMaxFactor(kB, bound);
// 		if (temp <= 1)
// 			break;

// 		if (kA / temp == floor(kA / temp))
// 		{
// 			ret = false;
// 			break;
// 		}
// 		bound = temp - 1;
// 	}

// 	return ret;
// }


// 	bool rslt = false;
// 	if (sum > kNum)
// 		rslt = true;
// 	else
// 		rslt = false;
// 	return rslt;
// }

