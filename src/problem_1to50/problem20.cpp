//Factorial digit sum
/*
n! means n ¡Á (n ? 1) ¡Á ... ¡Á 3 ¡Á 2 ¡Á 1

For example, 10! = 10 ¡Á 9 ¡Á ... ¡Á 3 ¡Á 2 ¡Á 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include "../header.h"
#include "../big_number_class.h"

void Problem20()
{
	BigNumberC big_number("1");

	for(int i = 100; i > 0; --i)
		big_number.Multiply(i);

	cout << "100! is : ";
	big_number.Print();
	cout << "100! -- ";
	cout << big_number.GetDigitsSum() << endl;
}
