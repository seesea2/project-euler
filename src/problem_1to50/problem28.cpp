//Number spiral diagonals
/*
Starting with the number 1 and moving to the right in a clockwise direction 
a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include "../header.h"

//In the spiral matrix, there is pattern:
//for matrix with size n, if n is even, the nth number is on diagonal.
//for matrix with size n, if n is odd, the first & nth number is on diagonal
//below caculation is basing on this pattern.
void Problem28() {
	const int kSpiralMatrixSize = 1001;
	//const int kSpiralMatrixSize = 5;

	double sum_of_diagonals = 0.0;			//final rslt = 669171001
	int spiral_matrix_size = 0;
	int num = 0;
	int steps_in_new_spiral = 0;

	spiral_matrix_size = 1;
	while(1)
	{
		++num;
		++steps_in_new_spiral;

		if(spiral_matrix_size % 2 == 0) //even spiral matrix
		{
			if(steps_in_new_spiral == spiral_matrix_size)
			{
				steps_in_new_spiral = 0;
				sum_of_diagonals += num;
			}
		}
		else if(spiral_matrix_size % 2 == 1) //odd spiral matrix
		{
			if(steps_in_new_spiral == 1)
			{
				sum_of_diagonals += num;
			}
			else if(steps_in_new_spiral == spiral_matrix_size)
			{
				steps_in_new_spiral = 1;
				sum_of_diagonals += num;
			}
		}

		if(num == spiral_matrix_size * spiral_matrix_size)
		{
			++spiral_matrix_size;
			steps_in_new_spiral = 0;
		}

		if(spiral_matrix_size > kSpiralMatrixSize)
			break;
	}

	cout << "sum_of_diagonals : " << sum_of_diagonals << endl << endl;
}