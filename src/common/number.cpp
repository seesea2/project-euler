#include "number.h"

bool IsEven(const uint64_t kNum)
{
	if (kNum == 0)
		return false;
	if (kNum % 2)
		return false;
	return true;
}

bool NumToBinary(const int num, string &binary)
{
	// cout << num << endl;
	try
	{
		binary.clear();
		auto n = num;
		while (n)
		{
			binary += to_string(n % 2);
			n = n / 2;
		}

		reverse(binary.begin(), binary.end());
		return true;
	}
	catch (...)
	{
		return false;
	}
}
