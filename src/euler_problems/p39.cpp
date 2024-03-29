// Integer right triangles
/*
If p is the perimeter of a right angle triangle_data with integral length sides,
 {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p <= 1000, is the number of solutions maximised?

	Answer:
	840
*/

#include "1_99.h"

bool P39()
{
	try
	{
		int a, b, c;
		int most = 0, qty;

		int perimeter, best_perimeter;

		for (perimeter = 1; perimeter <= 1000; ++perimeter)
		{
			cout << "perimeter: " << perimeter << endl;
			qty = 0;
			for (c = perimeter; c > 0; --c)
			{
				if (c < perimeter / 3)
					break;

				for (b = c; b > 0; --b)
				{
					a = perimeter - c - b;
					if (a * a + b * b == c * c)
						++qty;
				}
			}

			if (qty > most)
			{
				most = qty;
				best_perimeter = perimeter;
			}
		}

		cout << "Parameter of integer right triangles : " << best_perimeter << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
