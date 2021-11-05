/*
The number, 1406357289, is a 0 to 9 pandigital number because 
it is made up of each of the digits 0 to 9 in some order, 
but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. 
In this way, we note the following:

    d2d3d4=406 is divisible by 2
    d3d4d5=063 is divisible by 3
    d4d5d6=635 is divisible by 5
    d5d6d7=357 is divisible by 7
    d6d7d8=572 is divisible by 11
    d7d8d9=728 is divisible by 13
    d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.


Answer:  16695334890

*/

#include "1_99.h"

bool P43()
{
    try
    {
        cout << "preparing pan_numbers" << endl;
        vector<string> pan_numbers;
        PanNumbers("0123456789", pan_numbers);

        int divisors[] = {0, 0, 2, 3, 5, 7, 11, 13, 17};
        uint64_t sum = 0;
        for (auto &num : pan_numbers)
        {
            cout << "check: " << num << endl;

            bool bOk = true;
            // for d2d3d4 ... d8d9d10
            for (size_t ind = 2; ind <= 8; ++ind)
            {
                // cout << "ind: " << ind << endl;
                auto dn_dn1_dn2 = stoull(num.substr(ind - 1, 3));
                // cout << "dn_dn1_dn2: " << dn_dn1_dn2 << endl;
                if (dn_dn1_dn2 % divisors[ind])
                {
                    bOk = false;
                    break;
                }
            }
            if (!bOk)
                continue;

            sum += stoull(num);
        }
        cout << "Answer: " << sum << endl;
        return true;
    }
    catch (...)
    {
        cout << "Exception" << endl;
        return false;
    }
}