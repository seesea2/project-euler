/*

We shall say that an n-digit number is pandigital 
if it makes use of all the digits 1 to n exactly once. 
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

Answer:  7652413

*/

#include "1_99.h"

// construct num in format: high_digits + all sequences of low_digits.
bool construct_num(const string high_digits, const string low_digits, vector<string> &rslt)
{
    try
    {
        // cout << "construct_num: " << high_digits << " + " << low_digits << endl;
        if (low_digits.length() == 1)
        {
            // cout << "contruct: " << high_digits + low_digits << endl;
            rslt.push_back(high_digits + low_digits);
            return true;
        }

        for (auto i = 0; i < low_digits.length(); ++i)
        {
            auto temp_digits = low_digits;
            temp_digits.erase(i, 1);
            construct_num(high_digits + low_digits[i], temp_digits, rslt);
        }
        return true;
    }
    catch (...)
    {
        return false;
    }
}

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
            construct_num("", all_digits.substr(0, decimals), numbers);

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
    }
    catch (...)
    {
        cout << "Exception" << endl;
        return false;
    }
}