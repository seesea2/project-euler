//Maximum path sum II
/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, 
the maximum total from top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), 
a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, 
as there are 299 altogether! If you could check one trillion (1012) routes every second 
it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
*/

#include "../header.h"
#include "../problem_api_1to50.h"

void Problem67() {
	//input "p067_triangle.txt"
	ifstream ifs("problem_61to90/p067_triangle.txt", ifstream::in);
	string str;
	int triangle_input_rows = 0;
	while(getline(ifs, str))
	{
		++triangle_input_rows;
	}

	int triangle_data_rows = triangle_input_rows, triangle_data_cols = triangle_input_rows + triangle_input_rows - 1;
	cout << "triangle_data_rows : " << triangle_data_rows << "    triangle_data_cols : " << triangle_data_cols << endl;
	int **triangle_data = new int*[triangle_data_rows];
	for(int i = 0; i < triangle_data_rows; ++i)
	{
		triangle_data[i] = new int[triangle_data_cols];
		for(int j = 0; j < triangle_data_cols; ++j)
			triangle_data[i][j] = 0;
	}

	int triangle_row_ind = 0, nth_in_row = 0;
	int data_num = 0;
	ifs.clear();
	ifs.seekg(0, ios::beg);
	while(ifs >> str)
	{
		data_num = stoi(str);
		triangle_data[triangle_row_ind][(triangle_data_rows-1 - triangle_row_ind) + nth_in_row * 2] = data_num;
		++nth_in_row;
		if(nth_in_row > triangle_row_ind)
		{
			++triangle_row_ind;
			nth_in_row = 0;
		}
	}
	ifs.clear();
	ifs.close();

	//TriangleMaxPathSum() was define for Problem18()
	double rslt =  TriangleMaxPathSum(triangle_data, triangle_data_rows, triangle_data_cols);
	cout << "Max path sum is : " << rslt << endl << endl;

	for(int i = 0; i < triangle_data_rows; ++i)
	{
		delete [] triangle_data[i], triangle_data[i] = 0;
	}
	delete [] triangle_data, triangle_data = NULL;
}