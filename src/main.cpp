#include "header.h"
#include "problem_apis.h"
#include "big_number_class.h"
#include "math_functions.h"


void main()
{
	cout << fixed;
	cout.precision(0);

	clock_t clock_time;
	clock_time = clock();

	cout << 40 % 100 - 40 % 10 << endl;

	//Problem34();

	clock_time = clock() - clock_time;
	cout << "Takes time seconds : " << clock_time << endl;
	system("pause");
}


#if 0 //shuffle number for TOTO
#include <chrono>
#include <random>
	vector<int> int_vector;

	int_vector.clear();
	for(int t = 1; t < 50; ++t)
		int_vector.push_back(t);

	unsigned long seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle (int_vector.begin(), int_vector.end(), std::default_random_engine(seed));

	for(vector<int>::iterator it = int_vector.begin(); it != int_vector.end(); ++it)
		cout << *it << endl;
#endif


#if 0 
class LEXICOGRAPHIC_ORDER_NUMBER
{
public:
	LEXICOGRAPHIC_ORDER_NUMBER(const char*);

	BigNumberC Number;
};
LEXICOGRAPHIC_ORDER_NUMBER::LEXICOGRAPHIC_ORDER_NUMBER(const char*construct)
{
	Number = BigNumberC (construct);
}
#endif
