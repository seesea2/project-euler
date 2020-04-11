// Special Pythagorean triplet
/*
	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
	a^2 + b^2 = c2

	For example, 3^2 + 4^2 = 9 + 16 = 2^5 = 52.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.

	Answer:
	31875000
*/

#include "1_50.h"

void p9()
{
	int a, b, c;
	bool rslt = false;

	for (a = int(1000 / 3); a > 1; --a)
	{
		for (c = int(1000 / 3); c < 1000; ++c)
		{
			b = 1000 - a - c;
			if (b <= a || b >= c)
				continue;

			if (a * a + b * b == c * c)
			{
				rslt = true;
				break;
			}
		}

		if (rslt)
			break;
	}

	if (rslt)
	{
		cout << a << " : " << b << " : " << c << endl;
		cout << "Product : " << a * b * c << endl;
	}
	else
		cout << "failed" << endl;
}