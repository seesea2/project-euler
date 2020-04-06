//Permuted multiples
/*
It can be seen that the number, 125874, and its double, 251748, 
contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, 
and 6x, contain the same digits.
*/

#include "../header.h"
#include "../big_number_class.h"


void Problem52()
{
	BigNumberC num(0), temp;

	do
	{
		num.Plus(BigNumberC(1));
		//lych num.Print();

		temp = num;
		temp.Multiply(2);
		if(!num.HasSameDigitsQty(temp))
			continue;

		temp = num;
		temp.Multiply(3);
		if(!num.HasSameDigitsQty(temp))
			continue;

		temp = num;
		temp.Multiply(4);
		if(!num.HasSameDigitsQty(temp))
			continue;

		temp = num;
		temp.Multiply(5);
		if(!num.HasSameDigitsQty(temp))
			continue;

		temp = num;
		temp.Multiply(6);
		if(!num.HasSameDigitsQty(temp))
			continue;

		num.Print();
		break;
	}while(1);

}