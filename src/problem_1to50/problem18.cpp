//Maximum path sum I
/*
By starting at the top of the triangle_data below and moving to adjacent numbers on the row below, 
the maximum total from top to bottom is 23.

                3
               7 4
              2 4 6
             8 5 9 3
That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle_data below:

                     75
                    95 64
                  17 47 82
                18 35 87 10
               20 04 82 47 65
             19 01 23 75 03 34
            88 02 77 73 07 63 67
          99 65 04 28 06 16 70 92
         41 41 26 56 83 40 80 70 33
       41 48 72 33 47 32 37 16 94 29
      53 71 44 65 25 43 91 52 97 51 14
     70 11 33 28 77 73 17 78 39 68 17 57
   91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. 
However, Problem 67, is the same challenge with a triangle_data containing one-hundred rows; 
it cannot be solved by brute force, and requires a clever method! ;o)
*/



#include "../header.h"
#include "../problem_api_1to50.h"

void InputTriangleData();


void Problem18() {
	string triangle_input = 
"75 \
95 64 \
17 47 82 \
18 35 87 10 \
20 04 82 47 65 \
19 01 23 75 03 34 \
88 02 77 73 07 63 67 \
99 65 04 28 06 16 70 92 \
41 41 26 56 83 40 80 70 33 \
41 48 72 33 47 32 37 16 94 29 \
53 71 44 65 25 43 91 52 97 51 14 \
70 11 33 28 77 73 17 78 39 68 17 57 \
91 71 52 38 17 14 91 43 58 50 27 29 48 \
63 66 04 68 89 53 67 30 73 16 69 87 40 31 \
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

	//use triangle_input data to form triangle_data matrix with last 2 rows such as below for ruther analysis
	//00 63 00 66 00 04 00 68 00 89 00 53 00 67 00 30 00 73 00 16 00 69 00 87 00 40 00 31 00
	//04 00 62 00 98 00 27 00 23 00 09 00 70 00 98 00 73 00 93 00 38 00 53 00 60 00 04 00 23
	int triangle_data_rows = 0, triangle_data_cols = 0, **triangle_data = NULL; //triangle_data should be 15 rows & 29 cols
	int data_num = 0;
	int triangle_row_ind = 0, nth_in_row = 0;

	ofstream oo;
	oo.open("test.txt");

	triangle_row_ind = 1; //first row already have. It is before find(' ').
	size_t found = 0;
	//only n numbers in the n row. count row_qty basing on this.
	while(1)
	{
		found = triangle_input.find(' ', found + 1);
		if(found != string::npos)
		{
			++nth_in_row;
			if(nth_in_row >= triangle_row_ind)
			{
				nth_in_row = 0;
				++triangle_row_ind;
			}
		}
		else
			break;
	}
	triangle_data_rows = triangle_row_ind, triangle_data_cols = triangle_data_rows + triangle_data_rows - 1;
	oo << "triangle_data_rows : " << triangle_data_rows << "   triangle_data_cols : " << triangle_data_cols << endl;
	triangle_data = new int*[triangle_data_rows];
	for(int i = 0; i < triangle_data_rows; ++i)
	{
		triangle_data[i] = new int[triangle_data_cols];
		for(int j = 0; j < triangle_data_cols; ++j)
			triangle_data[i][j] = 0;
	}

	//recheck triangle_input and assigne each data to triangle_data[row, col].
	//it is also basing on: only n numbers in the n row.
	triangle_row_ind = 0;
	nth_in_row = 0;
	while(triangle_input.length() > 0)
	{
		//get data_num from string of triangle_input.
		size_t found = triangle_input.find(' ');
		if(found != string::npos)
		{
			data_num = stoi(triangle_input.substr(0, found));
			triangle_input = triangle_input.substr(found + 1);
		}
		else
		{
			data_num = stoi(triangle_input);
			triangle_input.clear();
		}
 
		//assign the data_num to triangle_data
		triangle_data[triangle_row_ind][(triangle_data_rows-1 - triangle_row_ind) + nth_in_row * 2] = data_num;
		++nth_in_row;

		if(nth_in_row > triangle_row_ind)
		{
			++triangle_row_ind;
			nth_in_row = 0;
		}
	}

	oo << "Input triangle_data is : " << endl;
	for(int i = 0; i < triangle_data_rows; ++i)
	{
		for(int j = 0; j < triangle_data_cols; ++j)
			oo << setw(4) << triangle_data[i][j];

		oo << endl;
	}
	oo << endl;

	double rslt =  TriangleMaxPathSum(triangle_data, triangle_data_rows, triangle_data_cols);
	oo << "Max path sum is : " << rslt << endl;
	cout << "Output is in test.txt. Max path sum is : " << rslt << endl;

	for(int i = 0; i < triangle_data_rows; ++i)
	{
		delete [] triangle_data[i], triangle_data[i] = 0;
	}
	delete [] triangle_data, triangle_data = NULL;

	oo.close();
	oo.clear();

}

//To get result of max path sum from top to bottom.
//Here check from bottom to top, get best total of each node.
double TriangleMaxPathSum(int **triangle_data, const int kRow, const int kCol) {
	double *node_best_total = new double[kCol], *last_node_best_total = new double[kCol];
	for(int col = 0; col < kCol; ++col)
	{
		node_best_total[col] = 0.0;
		last_node_best_total[col] = 0.0;
	}

	for(int row = kRow - 1; row >= 0; --row)
	{
		for(int col = 0; col < kCol - 1; ++col)
		{
			if(row == kRow - 1)
			{
				node_best_total[col] = last_node_best_total[col] = triangle_data[row][col];
			}
			else if(col > 0 && col + 1 < kCol - 1)
			{
				node_best_total[col] = triangle_data[row][col] + max(last_node_best_total[col - 1], last_node_best_total[col + 1]);
			}
		}
		
		for(int col = 0; col < kCol - 1; ++col)
			last_node_best_total[col] = node_best_total[col]; 
	}

	double rslt = node_best_total[kCol / 2];
	delete [] node_best_total;
	delete [] last_node_best_total;

	return rslt;
}