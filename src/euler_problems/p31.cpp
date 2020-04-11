// Coin sums
/*
In England the currency is made up of pound(e) and pence(p). 
There are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, e1(100p) and e2(200p).

It is possible to make 2 pound in the following way:

    1xe1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p

How many different ways can e2 be made using any number of coins?


	Answer:
	73682
*/

#include "1_99.h"

bool P31()
{
	try
	{
		int different_ways = 0;

		int sum1, sum2, sum3, sum4, sum5, sum6, sum7;
		const int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};

		for (int a = 0;; ++a)
		{
			sum1 = a * coins[0];
			if (sum1 > coins[7])
				break;

			for (int b = 0;; ++b)
			{
				sum2 = b * coins[1];
				if (sum2 > coins[7])
					break;

				for (int c = 0;; ++c)
				{
					sum3 = c * coins[2];
					if (sum3 > coins[7])
						break;

					for (int d = 0;; ++d)
					{
						sum4 = d * coins[3];
						if (sum4 > coins[7])
							break;

						for (int e = 0;; ++e)
						{
							sum5 = e * coins[4];
							if (sum5 > coins[7])
								break;

							for (int f = 0;; ++f)
							{
								sum6 = f * coins[5];
								if (sum6 > coins[7])
									break;

								for (int g = 0;; ++g)
								{
									sum7 = g * coins[6];
									if (sum7 > coins[7])
										break;

									if (sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 == coins[7])
										++different_ways;
								}
							}
						}
					}
				}
			}
		}

		different_ways += 1; // use only 2$.

		cout << "Different ways of $2: " << different_ways << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
