/*

We shall say that an n-digit number is pandigital 
if it makes use of all the digits 1 to n exactly once. 
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

Answer:  7652413

*/

#include "1_99.h"

// obvious not prime number.
bool NonPrime(string num)
{
    if (num.back() == '2' || num.back() == '4' || num.back() == '5' ||
        num.back() == '6' || num.back() == '8' || num.back() == '0')
    {
        return true;
    }
    return false;
}

bool P41()
{
    try
    {
        const string all_digits = "123456789";
        for (int decimals = 9; decimals >= 4; --decimals)
        {
            vector<string> numbers;
            cout << "construct_num of " + to_string(decimals) + " digits." << endl;
            PanNumbers(all_digits.substr(0, decimals), numbers);

            cout << "clean up non prime numbers" << endl;
            numbers.erase(remove_if(numbers.begin(), numbers.end(), NonPrime), numbers.end());

            cout << "sort numbers in decreasing" << endl;
            sort(numbers.rbegin(), numbers.rend());

            for (auto &num : numbers)
            {
                cout << "check: " << num << endl;
                if (IsPrime(stoi(num)))
                {
                    cout << "Answer: " << num << endl;
                    return true;
                }
            }
        }
        cout << "no answer found" << endl;
        return false;
    }
    catch (...)
    {
        cout << "Exception" << endl;
        return false;
    }
}