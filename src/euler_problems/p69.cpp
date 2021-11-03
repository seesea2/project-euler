// Totient maximum

#include "1_99.h"

const int MAX_RANGE = 1000000;
// const int MAX_RANGE = 10;

vector<set<uint64_t>> factors_list;

int get_phi_n(uint64_t n)
{
	int qty = 1; // 1 is relative prime to all numbers

	try
	{
		bool bStop = false;
		for (auto &factors : factors_list)
		{
			bool bCommonFactor = false;
			for (auto &factor : factors)
			{
				if (factor >= n)
				{
					bStop = true;
					break;
				}

				if (n / factor == double(n) / factor)
				{
					bCommonFactor = true;
					break;
				}
			}
			if (bStop)
				break;

			if (!bCommonFactor)
				qty += 1;
		}

		cout << n << " -  phi_n: " << qty << endl;
		return qty;
	}
	catch (...)
	{
		return qty;
	}
}

bool P69()
{
	try
	{
		double n_divid_phi, max_n_divid_phi = 0;
		uint64_t n, phi_n, best_n;

		// prepare to get phi_n
		for (int num = 2; num < MAX_RANGE; ++num)
		{
			// cout << "prepare factors: " << num << endl;
			auto factors = GetFactors(num);
			factors.insert(num); //factors including self
			factors_list.push_back(factors);
		}

		for (n = 2; n <= MAX_RANGE; ++n)
		{
			// phi_n = get_phi_n(n);
			phi_n = 1; // 1 is in phi_n for all number.
			for (auto &factors : factors_list)
			{
				bool bStop = false;
				bool bCommonFactor = false;
				for (auto &factor : factors)
				{
					if (factor >= n)
					{
						bStop = true;
						break;
					}

					if (n / factor == double(n) / factor)
					{
						bCommonFactor = true;
						break;
					}
				}
				if (bStop)
					break;

				if (!bCommonFactor)
				{
					phi_n += 1;
					if (max_n_divid_phi > double(n) / phi_n)
						break;
				}
			}

			n_divid_phi = double(n) / phi_n;
			if (n_divid_phi > max_n_divid_phi)
			{
				best_n = n;
				max_n_divid_phi = n_divid_phi;
			}
		}

		cout << best_n << " has max n/phi(n) as " << max_n_divid_phi << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}