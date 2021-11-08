/*Large non-Mersenne prime

The first known prime found to exceed one million digits was discovered in 1999, 
and is a Mersenne prime of the form 26972593−1; it contains exactly 2,098,960 digits. 
Subsequently other Mersenne primes, of the form 2p−1, 
have been found which contain more digits.

However, in 2004 there was found a massive non-Mersenne prime 
which contains 2,357,207 digits: 28433×27830457+1.

Find the last ten digits of this prime number.

    Answer:  8739992577
*/

#include "1_99.h"

bool P97()
{
    try
    {
        const uint64_t mod = 10000000000;
        uint64_t num = 28433;
        for (size_t i = 0; i < 7830457; ++i)
        {
            cout << "count pow: " << i << endl;
            num *= 2;
            num %= mod;
        }
        num += 1;

        cout << "Answer: " << num << endl;
        return true;
    }
    catch (...)
    {
        return false;
    }
}