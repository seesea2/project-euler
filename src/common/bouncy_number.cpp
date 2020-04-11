#include "header.h"

bool IsDecreasingNumber(const uint64_t kNum)
{
  string str = to_string(kNum);
  for (auto a = str.begin(); a != str.end() - 1; ++a)
  {
    if (*a < *(a + 1))
      return false;
  }

  return true;
}

bool IsIncreasingNumber(const uint64_t kNum)
{
  string str = to_string(kNum);
  for (auto a = str.begin(); a != str.end() - 1; ++a)
  {
    if (*a > *(a + 1))
      return false;
  }

  return true;
}