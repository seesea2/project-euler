#include "header.h"
#include "number.h"
#include "euler.h"

int main()
{
	// cout << INT_MAX << endl;
	// cout << UINT64_MAX << endl;
	try
	{
		cout << fixed;
		cout.precision(0);

		do
		{
			cout << "Input Project Euler Problem ID (0 to exit) : ";
			int id = 0;
			cin >> id;
			if (id == 0)
				break;

			clock_t clock_time;
			clock_time = clock();

			if (g_euler.Func(id))
				g_euler.Func(id)();
			else
				cout << "Solution not available." << endl;

			clock_time = (clock() - clock_time) / 1000.0;
			cout << "Takes time: " << clock_time << " seconds" << endl;
			cout << string(30, '*') << endl
				 << endl;
		} while (1);

		return 0;
	}
	catch (...)
	{
		return 1;
	}
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
