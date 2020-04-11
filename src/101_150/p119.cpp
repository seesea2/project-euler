//Digit power sum
/*
The number 512 is interesting because it is equal to the sum of its digits raised to some power: 5 + 1 + 2 = 8, 
and 83 = 512. Another example of a number with this property is 614656 = 284.

We shall define an to be the nth term of this sequence and insist 
that a number must contain at least two digits to have a sum.
You are given that a2 = 512 and a10 = 614656.
Find a30.
*/

#include "101_150.h"
#include "debug.h"

bool IsInterestingNum(const BigNumber kObj);

void p119()
{
	DebugFunctionBegin("p119");

	const int kAn = 10;
	BigNumber num("1");
	int nth = 0;
	// while (1)
	// {
	// 	cout << "test : " + num.GetIntegerPart() << endl;
	// 	DebugPrint("while 1 check : " + num.GetIntegerPart());
	// 	if (IsInterestingNum(num))
	// 	{
	// 		++nth;
	// 		cout << nth << "th number is :" << num << endl;
	// 	}

	// 	num += BigNumber(1);
	// 	DebugPrint("while 2 check : " + num.GetIntegerPart());
	// 	if (nth >= kAn)
	// 		break;
	// }
	DebugFunctionEnd("p119");
}

bool IsInterestingNum(const BigNumber kObj)
{
	DebugFunctionBegin("IsInterestingNum(const BigNumber kObj)");

	bool rslt = false;
	// if (kObj.GetIntegerPart().length() > 1)
	// {
	// 	// string digits_sum_string = kObj.GetDigitsSumString();
	// 	// BigNumber power = BigNumber(digits_sum_string) * BigNumber(digits_sum_string);

	// 	// DebugPrint("power = : " + power.GetIntegerPart());
	// 	if (power != BigNumber(1))
	// 	{
	// 		while (1)
	// 		{
	// 			DebugPrint("power = : " + power.GetIntegerPart());
	// 			if (power == kObj)
	// 			{
	// 				rslt = true;
	// 				break;
	// 			}
	// 			else if (power > kObj)
	// 				break;

	// 			power *= BigNumber(digits_sum_string);
	// 		}
	// 	}
	// }

	DebugFunctionEnd("IsInterestingNum(const BigNumber kObj)");
	return rslt;
}