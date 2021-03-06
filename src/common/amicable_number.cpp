#include "number.h"

uint64_t GetAmicableNum(const uint64_t kNum)
{
  auto factors = GetFactors(kNum);
  if (factors.size() <= 0)
    return 0;

  uint64_t sum1 = 1;
  for (auto a = factors.begin(); a != factors.end(); ++a)
    sum1 += *a;
  if (kNum == sum1)
    return 0;

  factors = GetFactors(sum1);
  uint64_t sum2 = 1;
  for (auto a = factors.begin(); a != factors.end(); ++a)
    sum2 += *a;

  if (kNum == sum2)
    return sum1;
  return 0;
}
