/* Counting fractions in a range

Consider the fraction, n/d, where n and d are positive integers. 
If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, 
we get:
1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 
4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted set of 
reduced proper fractions for d ≤ 12,000?

    Answer: 7295372
    
*/

#include "1_99.h"

bool P73()
{
    try
    {
        set<double> fractions;
        const int max = 12000;
        // const int max = 8;
        for (int d = 1; d <= max; ++d)
        {
            // cout << "construct fractions for d: " << d << endl;
            for (int n = 1; n < d; ++n)
            {
                if (std::gcd(d, n) != 1)
                    continue;
                double val = n / double(d);
                fractions.insert(val);
            }
        }
        cout << fractions.size() << endl;

        uint64_t cnt = 0;
        for (auto &f : fractions)
        {
            if (f >= 1 / double(2))
                break;
            if (f > 1 / double(3))
                cnt += 1;
        }
        cout << "Answer: " << cnt << endl;
        return true;
    }
    catch (std::exception &e)
    {
        cout << "Exception: " << e.what() << endl;
        return false;
    }
    catch (...)
    {
        cout << "Exception" << endl;
        return false;
    }
}