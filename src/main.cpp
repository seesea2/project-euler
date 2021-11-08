#include "euler.h"

int main()
{
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
		} while (0); // liych to debug

		return 0;
	}
	catch (...)
	{
		return 1;
	}
}
