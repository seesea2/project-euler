/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, 
find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000


    Answer: ?

*/

#include "1_99.h"

// int getDigit(int n)
// {
//     uint64_t r, s = 0, k = 0;
//     while (s < n)
//     {
//         r = s;
//         s += 9 * 10 * *k++ * k;
//     }
//     uint64_t h = n - r - 1;
//     uint64_t t = 10 * *(k - 1) + h / k;
//     uint64_t p = h % k;
//     return +String(t)[p];
// }

bool P40()
{
    try
    {
        string digits = "1234567890";

        cout << "no answer found" << endl;
        return false;
    }
    catch (...)
    {
        cout << "Exception" << endl;
        return false;
    }
}