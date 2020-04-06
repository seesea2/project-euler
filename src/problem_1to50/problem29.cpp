//Distinct powers
#include "../header.h"
#include "../big_number_class.h"


void Problem29()
{
	double qty = 0;

	for(int a = 90; a <= 100; ++a)
	{
		for(int b = 90; b <= 100; ++b)
		{
			BigNumberC tt;
			tt.SetToPowerOfInt(a, b);
			tt.Print();
		}
	}

}