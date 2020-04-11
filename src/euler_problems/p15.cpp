// Lattice paths
/*
	Starting in the top left corner of a 2x2 grid,
	and only being able to move to the right and down, 
	there are exactly 6 routes to the bottom right corner.

	How many such routes are there through a 20x20 grid?

	Answer:
	137846528820
*/

#include "1_99.h"

bool P15()
{
	try
	{
		const int kRows = 20, kCols = 20;

		//Because: routes(m, n) = routes(m + 1, n) + routes(m, n + 1)
		//Manage to count routes of each corner from right bottom towards left top.
		//final routes(0, 0) will be the requested qty.

		uint64_t routes_matrix[kRows + 1][kCols + 1];
		int row = 0, col = 0, total = kRows + kCols;
		while (total >= 0)
		{
			row = kRows, col = total - row;
			do
			{
				if (row >= 0 && row <= kRows && col >= 0 && col <= kCols)
				{
					//reached right bottom
					if (row == kRows && col == kCols)
						routes_matrix[row][col] = 0;
					//at right or bottom edge. One only way to move.
					else if (row == kRows || col == kCols)
						routes_matrix[row][col] = 1;
					else
						routes_matrix[row][col] =
							routes_matrix[row + 1][col] + routes_matrix[row][col + 1];
				}

				--row;
				++col;
			} while (row >= 0 && col <= kCols);

			total -= 1;
		}

		cout << "Routes through 20x20 grid : " << routes_matrix[0][0] << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}