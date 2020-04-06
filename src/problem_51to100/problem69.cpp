//Totient maximum
#include "../header.h"
#include "../math_functions.h"

int get_phi_n(const double n)
{
	int qty = 0;

	qty = 1; //1 is phi(n) for all numbers
	for(int i = int(n-1); i > 1; --i)
	{
		if(IsRelativelyPrime(n, i))
			++qty;
	}

	cout << n << " - " << qty << endl;
	return qty;
}

void problem69()
{
	const int MAX_RANGE = 1000000;

	double max_n_divid_phi = 0, phi_n;
	int n, best_n;

	for(n = 1; n <= MAX_RANGE; ++n)
	{
		phi_n = get_phi_n(n);
		if(double(n) / phi_n > max_n_divid_phi)
		{
			best_n = n;
			max_n_divid_phi = double(n) / phi_n;
		}
	}

	cout << best_n << " has max n/phi(n) as " << max_n_divid_phi << endl;
}