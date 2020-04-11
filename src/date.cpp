#include "number.h"

bool IsLeapYear(const int kYear)
{
	if (kYear % 400 == 0)
		return true;
	else if (kYear % 100 == 0)
		return false;
	else if (kYear % 4 == 0)
		return true;
	else
		return false;
}
