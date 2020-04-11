#include "number.h"

bool IsPerfectNum(const uint64_t kNum)
{
  auto factors = GetFactors(kNum);

  uint64_t sum = 1;
  for (auto &a : factors)
    sum += a;

  if (kNum == sum)
    return true;

  return false;
}

bool IsAbundantNum(const uint64_t kNum)
{
  auto factors = GetFactors(kNum);

  uint64_t sum = 1;
  for (auto &a : factors)
    sum += a;

  if (sum > kNum)
    return true;

  return false;
}

bool IsDeficientNum(const uint64_t kNum)
{
  auto factors = GetFactors(kNum);

  uint64_t sum = 1;
  for (auto &a : factors)
    sum += a;

  if (sum < kNum)
    return true;

  return false;
}
