#include "number.h"

bool construct(const string high_digits, const string low_digits, vector<string> &pan_numbers);

// construct numbers in all sequence of bases.
bool PanNumbers(const string bases, vector<string> &pan_numbers)
{
    try
    {
        return construct("", bases, pan_numbers);
    }
    catch (...)
    {
        return false;
    }
}

// construct num in format: high_digits + all sequences of low_digits.
bool construct(const string high_digits,
               const string low_digits,
               vector<string> &pan_numbers)
{
    try
    {
        if (low_digits.length() == 1)
        {
            pan_numbers.push_back(high_digits + low_digits);
            return true;
        }

        for (size_t i = 0; i < low_digits.length(); ++i)
        {
            if (high_digits.empty() && low_digits[i] == '0')
                continue;
            auto temp_digits = low_digits;
            temp_digits.erase(i, 1);
            bool rslt = construct(high_digits + low_digits[i], temp_digits, pan_numbers);
            if (!rslt)
                return false;
        }
        return true;
    }
    catch (...)
    {
        return false;
    }
}
