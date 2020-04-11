//Divisibility of sum of divisors
/*
Let ��(n) be the sum of the divisors of n.
E.g. the divisors of 4 are 1, 2 and 4, so ��(4)=7.

The numbers n not exceeding 20 such that 7 divides ��(n) are:
4,12,13 and 20, the sum of these numbers being 49.

Let S(n,d) be the sum of the numbers i not exceeding n such that d divides ��(i).
So S(20,7)=49.

You are given: S(106,2017)=150850429 and S(109,2017)=249652238344557.

Find S(1011,2017)
*/

#include "500_599.h"

bool P565()
{
    try
    {
        return true;
    }
    catch (...)
    {
        return false;
    }
}