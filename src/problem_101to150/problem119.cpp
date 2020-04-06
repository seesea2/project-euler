//Digit power sum
/*
The number 512 is interesting because it is equal to the sum of its digits raised to some power: 5 + 1 + 2 = 8, 
and 83 = 512. Another example of a number with this property is 614656 = 284.

We shall define an to be the nth term of this sequence and insist 
that a number must contain at least two digits to have a sum.
You are given that a2 = 512 and a10 = 614656.
Find a30.
*/


#include "../header.h"
#include "../big_number_class.h"
#include "../debug_header.h"

bool IsInterestingNum(const BigNumberC kObj);

void Problem119() {
	DebugFunctionBegin("Problem119");
	
	const int kAn = 10;
	BigNumberC num("1");
	int nth = 0;
	while(1)
	{
		cout << "test : " + num.GetIntegerPart() << endl;
		DebugPrint("while 1 check : " + num.GetIntegerPart());
		if(IsInterestingNum(num))
		{
			++nth;
			cout << nth << "th number is :" << num << endl;
		}

		num += BigNumberC(1);
		DebugPrint("while 2 check : " + num.GetIntegerPart());
		if(nth >= kAn)
			break;
	}
	DebugFunctionEnd("Problem119");
}

bool IsInterestingNum(const BigNumberC kObj)
{
	DebugFunctionBegin("IsInterestingNum(const BigNumberC kObj)");

	bool rslt = false;
	if(kObj.GetIntegerPart().length() > 1)
	{
		string digits_sum_string = kObj.GetDigitsSumString();
		BigNumberC power = BigNumberC(digits_sum_string) * BigNumberC(digits_sum_string);

		DebugPrint("power = : " + power.GetIntegerPart());
		if(power != BigNumberC(1))
		{
			while(1)
			{
				DebugPrint("power = : " + power.GetIntegerPart());
				if(power == kObj) 
				{
					rslt = true;
					break;
				}
				else if(power > kObj)
					break;

				power *= BigNumberC(digits_sum_string);
			}
		}
	}

	DebugFunctionEnd("IsInterestingNum(const BigNumberC kObj)");
	return rslt;
}