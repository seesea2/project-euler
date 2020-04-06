//Arranged probability
/*
If a box contains twenty-one coloured discs, composed of fifteen blue discs and six red discs, 
and two discs were taken at random, it can be seen that the probability of taking two blue discs, 
P(BB) = (15/21)¡Á(14/20) = 1/2.

The next such arrangement, for which there is exactly 50% chance of taking two blue discs at random, 
is a box containing eighty-five blue discs and thirty-five red discs.

By finding the first arrangement to contain over 10 power 12 = 1,000,000,000,000 discs in total, 
determine the number of blue discs that the box would contain.
*/

#include "../header.h"
#include "../big_number_class.h"

//the question i.e.
//to get blue_discs and total_discs, 
//s.t. blue_discs x (blue_discs-1) x 2 == total_discs x (total_discs - 1) and total_discs > 10 power 12.
void Problem100() {

	BigNumberC left_rslt, right_rslt;
	//double total_discs = 1000000000000, up_boundary, down_boundary, blue_discs, rslt = 0.0;
	double total_discs = 100000000, up_boundary, down_boundary, blue_discs, rslt = 0.0;

	while(1)
	{
		up_boundary = total_discs;
		down_boundary = 0.0;
		right_rslt = BigNumberC(total_discs).Multiply(BigNumberC(total_discs - 1));

		cout << "Test total_discs : " << total_discs << endl;
		while(1)
		{
			//use binary search to speed up.
			blue_discs = floor((up_boundary + down_boundary)/2);
			left_rslt = BigNumberC(blue_discs);
			left_rslt.Multiply(BigNumberC(blue_discs - 1));
			left_rslt.Multiply(2);
			if(left_rslt.IsEqual(right_rslt) == true)
			{
				rslt = blue_discs;
				break;
			}

			left_rslt.Minus(right_rslt);
			if(left_rslt.IsPositiveNumber() == true)
				up_boundary = blue_discs;
			else
				down_boundary = blue_discs;

			if(up_boundary <= down_boundary + 1)
				break;
		}

		if(rslt > 0.0)
			break;
		total_discs += 1;
	}

	cout << "Total discs : " << total_discs << " - Blue discs : " << rslt << endl;
}
