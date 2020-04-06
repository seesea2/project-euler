#ifndef __MATHFUNCTIONS_H_INCLUDED__
#define __MATHFUNCTIONS_H_INCLUDED__

#include "header.h"


int    GetAmicableNumber(const int kNum);
double GetMaxFactorWithBoundary(const double kNum, const double kBoundary);
bool   IsAbundantNum(const double kNum);
bool   IsEvenNum(const double kNum);
bool   IsDeficientNum(const double kNum);
bool   IsDecreasingNumber(const int kNum);
bool   IsIncreasingNumber(const int kNum);
bool   IsLeapYear(const int kYear);
bool   IsPerfectNum(const double kNum);
bool   IsPrime(const double kNum);
bool   IsRelativelyPrime(const double kA, const double kB);



#endif
