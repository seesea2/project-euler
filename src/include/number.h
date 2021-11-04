#ifndef __NUMBER_H__
#define __NUMBER_H__

#include "header.h"

class BigNumber
{
public:
    BigNumber();
    BigNumber(const string kStr);
    BigNumber(const BigNumber &kBn);
    BigNumber(const uint64_t kUint);
    // BigNumber(const double kDb);
    ~BigNumber();

    friend ostream &operator<<(ostream &out, const BigNumber kObj);

    BigNumber operator+(const BigNumber &kObj);
    BigNumber operator-(const BigNumber &kBn);
    BigNumber operator*(const int kMultiplier);
    BigNumber &operator=(const BigNumber &kObj);
    BigNumber &operator+=(const BigNumber &kObj);
    BigNumber &operator-=(const BigNumber &kObj);
    BigNumber &operator*=(const int kMultiplier);
    BigNumber &operator*=(const BigNumber &kMultiplier);
    bool operator==(const BigNumber kObj) const;
    bool operator!=(const BigNumber kObj) const;
    bool operator>(const BigNumber kObj) const;
    bool operator<(const BigNumber kObj) const;

    BigNumber &Power(const int kPower);

    vector<int> number_;
    bool positive_;
};

uint64_t factorial(const int num);
uint64_t GetAmicableNum(const uint64_t kNum);
set<uint64_t> GetFactors(const uint64_t kNum);
bool IsAbundantNum(const uint64_t kNum);
bool IsEven(const uint64_t kNum);
bool IsDeficientNum(const uint64_t kNum);
bool IsDecreasingNumber(const uint64_t kNum);
bool IsIncreasingNumber(const uint64_t kNum);
bool IsLeapYear(const int kYear);
bool IsPerfectNum(const uint64_t kNum);
bool IsPrime(const uint64_t kNum);
bool PanNumbers(const string bases, vector<string> &pan_numbers);
bool NumToBinary(const int num, string &binary);

#endif // __NUMBER_H__
